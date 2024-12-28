#include "RLEList.h"
#include <stdlib.h>

struct RLEList_t{
    struct RLEList_t* next;
    int counter;
    char value;
}; 
static bool indexInBounds(RLEList list, int index) {
    if(list->counter == -1 || index < 0 || index >= RLEListSize(list)) // TODO: maybe should check if list is null
    {
        return false;
    }
    
    return true;
}
static RLEList getNodeByIndex(RLEList list, int index) {

    if(!indexInBounds(list,index))
    {
        return NULL;
    }
    
    RLEList currNode = list;
    while(currNode) 
    {
        index-= currNode->counter;
        if(index < 0) 
        {
            return currNode;
        }
        
        currNode = currNode->next;
    }
    return currNode;
}

static int getNumberOfNodes(RLEList list) {
    int numberOfNodes = 0;
    RLEList currNode = list;

    while(currNode != NULL)
    {
        numberOfNodes++;
        currNode = currNode->next;
    }
    return numberOfNodes;
}
// finds the size of the string of the number
static int getAmountOfDigitsInCounter(int num)
{
    int size = 1;
    while (num > 9)
    {
        num /= 10;
        size++;
    }
    return size;
}

static int getLengthOfStringOfList(RLEList list) {
    int size = 1; // the '\0' at the end of every string
    RLEList currNode = list;
    while(currNode) 
    {
        size++; // for the 'char'
        size+= getAmountOfDigitsInCounter(currNode->counter);// for the number
        size++; // '\n'
        currNode=currNode->next;
    }
    return size;
}

static int getPowerOfTen(int power) { 
    if(power == 0)
    {
        return 1;
    }

    int num = 10;
    for (int i = 1; i < power; i++)
    {
        num *= 10;
    }

    return num;
}
RLEList RLEListCreate() {
    RLEList newRleList = malloc(sizeof(*newRleList));
    if(!newRleList)
    {
        return NULL; 
    }

    newRleList->counter = -1;
    newRleList->value = '\0';
    newRleList->next = NULL;
    return newRleList;
}

void RLEListDestroy(RLEList list) {
    while(list) 
    {
        RLEList toDelete = list;
        list = list->next;
        free(toDelete);
    }

}

RLEListResult RLEListAppend(RLEList list, char value) { 
    if(!list || !value) 
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    if(list->counter == -1) 
    { // if it's the first node to be appended
        list->counter = 1;
        list->value = value;
        list->next = NULL;
        return RLE_LIST_SUCCESS;
    }

    RLEList lastNode = list;
    while((lastNode->next)) 
    {
        lastNode = lastNode->next;
    }

    if(lastNode->value == value) 
    {
            lastNode->counter++;
    } 

    else 
    { 
        RLEList newNode = RLEListCreate();
        if(!newNode) 
        {
            return RLE_LIST_OUT_OF_MEMORY;
        }

        lastNode->next = newNode;
        newNode->value = value;
        newNode->counter = 1;
        newNode->next = NULL;
    }

    return RLE_LIST_SUCCESS;
}

int RLEListSize(RLEList list) { 
    if(!list) 
    {
        return -1;
    }

    int size = 0;
    if(list->counter == -1)
    {
        return size;
    }

    RLEList tempNode = list;
    while(tempNode) 
    {
        size += tempNode->counter;
        tempNode = tempNode->next;
    }

    return size;
}

RLEListResult RLEListRemove(RLEList list, int index) {
    if(!list) 
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    if(!indexInBounds(list,index)) 
    {
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }

    if(index == 0 || index < list->counter) 
    {
        if (list->counter > 1) 
        {
            list->counter--;
        }

        else 
        {
            if(!(list->next))
            {
                list->counter = -1;
                list->value = '\0';
                list->next = NULL;
            }

            else if (list->next != NULL) 
            {
                RLEList tempNode = list->next;
                *list = *(list->next);//TODO: WHY DOES THIS WORK
                free(tempNode);
            }
        }
        return RLE_LIST_SUCCESS;
    }

    RLEList prevNode = getNodeByIndex(list, index - 1);
    RLEList nodeToDelete = getNodeByIndex(list, index);
    RLEList nextNode = getNodeByIndex(list, index + 1);
    if(nodeToDelete->counter > 1) 
    {
        nodeToDelete->counter--;
    }

    else
    {
        if(nextNode && (prevNode->value == nextNode->value))
        {
            prevNode->counter+=nextNode->counter;
            prevNode->next = nextNode->next;
            free(nodeToDelete);
            free(nextNode);
        }

        else
        {
            prevNode->next = nextNode;
            free(nodeToDelete);
        }

    }

    return RLE_LIST_SUCCESS;
}

char RLEListGet(RLEList list, int index, RLEListResult *result) {
    if(!list) 
    {
        *result = RLE_LIST_NULL_ARGUMENT;
        return 0;
    }
    
    if(!indexInBounds(list, index))
    {
        *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
        return 0;
    }

    if(result)
    {
        *result = RLE_LIST_SUCCESS;
    }

    return getNodeByIndex(list,index)->value;
}

char* RLEListExportToString(RLEList list, RLEListResult* result) {
    if(!list) 
    {
        *result = RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    
    int numOfNodes = getNumberOfNodes(list);
    int lengthOfString = getLengthOfStringOfList(list);
    char* stringToExport = malloc(lengthOfString);

    if(!stringToExport)
    {
        *result = RLE_LIST_OUT_OF_MEMORY;
        return NULL;
    }
    // now we built the string:
    RLEList currNode = list;
    int currStringIndex = 0;
    for(int i = 0; i < numOfNodes; i++)
    {
        stringToExport[currStringIndex++] = currNode->value;//CHARACTER

        int currCounter = currNode->counter;
        for(int j = 0; j < getAmountOfDigitsInCounter(currNode->counter); j++)
        {   
            int digitsInCurrNum = getAmountOfDigitsInCounter(currCounter);
            int currDigitOfCurrCounter = currCounter / getPowerOfTen(digitsInCurrNum - 1);
            stringToExport[currStringIndex++] = currDigitOfCurrCounter + '0'; // 0 is NULL in ascii
            currCounter -= currDigitOfCurrCounter *getPowerOfTen(digitsInCurrNum - 1);
        }
        stringToExport[currStringIndex++] = '\n'; // finished building one node
        currNode=currNode->next;
    }

    stringToExport[currStringIndex] = '\0'; // finished building the whole string
    if(result)
    {
        *result = RLE_LIST_SUCCESS;
    }

    return stringToExport;
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function) {
    
    if (!list || !map_function)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    RLEList currNode = list;

    for (int i = 0; i < getNumberOfNodes(list); i++)
    {
        currNode->value = map_function(currNode->value);
        currNode = currNode->next;
    }

    currNode = list;
    int currNodeIndex = 0;
    for (int i = 0; i < getNumberOfNodes(list); i++)
    {
        if (indexInBounds(list, i) && currNode->next)
        {
            if (currNode->value == currNode->next->value)
            {
                int indexesToDelete = currNode->next->counter;
                currNode->counter += currNode->next->counter;

                for (int j = 0; j < indexesToDelete; j++)
                {
                    RLEListRemove(list, currNodeIndex + currNode->counter);
                }
                i--;
            }

            else
            {
                currNodeIndex += currNode->counter;
                currNode = currNode->next;
            }
        }
    }

    return RLE_LIST_SUCCESS;
}