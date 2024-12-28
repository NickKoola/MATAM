import json
import os

NUM_OF_LETTERS_IN_ENGLISH = ord('z') - ord('a') + 1

CONFIG_FILE_NAME = 'config.json'
CONFIG_DICT_TYPE_KEY = 'type'
CONFIG_DICT_MODE_KEY = 'mode'
CONFIG_DICT_KEY_KEY = 'key'
CONFIG_DICT_CAESAR_TYPE = 'Caesar'
CONFIG_DICT_VIGENERE_TYPE = 'Vigenere'
CONFIG_DICT_ENCRYPT_MODE = 'encrypt'

TXT_FILE_SUFFIX = ".txt"
ENC_FILE_SUFFIX = '.enc'


def adjust_to_letter(char_ascii_code: int, is_capital=False):
    if is_capital:
        while char_ascii_code > ord('Z'):
            char_ascii_code -= NUM_OF_LETTERS_IN_ENGLISH

        while char_ascii_code < ord('A'):
            char_ascii_code += NUM_OF_LETTERS_IN_ENGLISH
    else:
        while char_ascii_code > ord('z'):
            char_ascii_code -= NUM_OF_LETTERS_IN_ENGLISH

        while char_ascii_code < ord('a'):
            char_ascii_code += NUM_OF_LETTERS_IN_ENGLISH

    return chr(char_ascii_code)


class CaesarCipher:
    """
    Constructor of Caesar Cipher class.

    @param: key - int, a numeric key for encryption/decryption.
    """
    def __init__(self, key):
        self.key = key

    """
    Encrypts the given text by Caesar Cipher.
    
    @param: plaintext - str, the text to encrypt.
    @returns:
        an encrypted string of the given text
    """
    def encrypt(self, plaintext: str):
        encrypted_str = ""
        for char in plaintext:
            if char.isalpha():
                encrypted_str += adjust_to_letter(ord(char) + self.key, char.isupper())
            else:
                encrypted_str += char

        return encrypted_str

    """
    Decrypts the given text by Caesar Cipher.
    
    @param: ciphertext - str, the text to decrypt.
    @returns:
        a decrypted string of the given text
    """
    def decrypt(self, ciphertext: str):
        reversed_cipher = CaesarCipher(-self.key)
        return reversed_cipher.encrypt(ciphertext)


class VigenereCipher:
    """
    Constructor of Vigenere Cipher class.

    @param: keys_list - a list of numeric keys for encryption/decryption.
    """
    def __init__(self, keys_list):
        self.keys_list = keys_list

    """
    Encrypts the given text by Vigenere Cipher.

    @param: plaintext - str, the text to encrypt.
    @returns:
        an encrypted string of the given text
    """
    def encrypt(self, plaintext: str):
        encrypted_message = ""
        keys_index = 0
        for char in plaintext:
            if char.isalpha():
                encrypted_message += adjust_to_letter(ord(char) + self.keys_list[keys_index], char.isupper())
                keys_index += 1
                if keys_index == len(self.keys_list):
                    keys_index = 0
            else:
                encrypted_message += char

        return encrypted_message

    """
    Decrypts the given text by Caesar Cipher.

    @param: ciphertext - str, the text to decrypt.
    @returns:
        a decrypted string of the given text
    """
    def decrypt(self, ciphertext: str):
        reversed_cipher = VigenereCipher([-key for key in self.keys_list])
        return reversed_cipher.encrypt(ciphertext)


"""
Creates a Vigenere Cipher according to a given string.
Each letter in the given string converted to a numeric key by it's lexicographic order.

@param: keyString - a string to be converted to keys
@returns: 
    a Vigenere Cipher according to the given string
"""


def getVigenereFromStr(keyString: str):
    keys_list = []
    for char in keyString:
        if char.isalpha():
            if char.isupper():
                keys_list.append(ord(char) - ord('A') + NUM_OF_LETTERS_IN_ENGLISH)
            else:
                keys_list.append(ord(char) - ord('a'))

    return VigenereCipher(keys_list)


def getCipherSystem(cipher_type: str, cipher_key):
    if cipher_type == CONFIG_DICT_CAESAR_TYPE:
        cipher_system = CaesarCipher(cipher_key)
    else:
        if type(cipher_key) == list:
            cipher_system = VigenereCipher(cipher_key)
        else:
            cipher_system = getVigenereFromStr(cipher_key)

    return cipher_system


def applyCipherAt(dir_path: str, cipher_system, toEncrypt: bool):
    input_files_suffix = TXT_FILE_SUFFIX if toEncrypt else ENC_FILE_SUFFIX
    output_files_suffix = ENC_FILE_SUFFIX if toEncrypt else TXT_FILE_SUFFIX
    files_list = os.listdir(dir_path)

    for file in files_list:
        if file.endswith(input_files_suffix):
            with open(dir_path + os.sep + file, 'r') as f:
                message = f.read()

            dec_file_name = file[:-len(input_files_suffix)] + output_files_suffix
            with open(dir_path + os.sep + dec_file_name, 'w') as f:
                f.write(cipher_system.encrypt(message) if toEncrypt else cipher_system.decrypt(message))


"""
This function encrypts/decrypts all the text files in the given directory.
It uses the method and keys that are given in a config file in the given directory.
The results are stored in new files at the same directory.

@param: dir_path - a directory which contains the file to encrypt/decrypt.
"""


def processDirectory(dir_path: str):
    with open(dir_path + os.sep + CONFIG_FILE_NAME, 'r') as f:
        config_dict = json.load(f)

    cipher_system = getCipherSystem(config_dict[CONFIG_DICT_TYPE_KEY], config_dict[CONFIG_DICT_KEY_KEY])
    applyCipherAt(dir_path, cipher_system, config_dict[CONFIG_DICT_MODE_KEY] == CONFIG_DICT_ENCRYPT_MODE)




