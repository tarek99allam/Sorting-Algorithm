/* ********************************************************************************************
/* @name     : SORTINGALGORITHM.C
/* @brief    : WIRTE PROGRAMS OF SORTING ALFORITHM
/* @author   : TAREK ALLAM
/***********************************************************************************************/

/*************************************** START INCLUDES ****************************************/
#include "errorState.h"
#include "stdTypes.h"
#include <stdio.h>

/*************************************** END INCLUDES ******************************************/
/*************************************** START HELPING FUNCTION ********************************/
static ES_t swap_Helper(uint32 *elemet1, uint32 *elemet2)
{

    *elemet1 = *elemet1 + *elemet2;
    *elemet2 = *elemet1 - *elemet2;
    *elemet1 = *elemet1 - *elemet2;
}
ES_t move_Right_Helper(uint32 arr[], uint32 startElement, uint32 endElement)
{
    uint32 counter, temp, temp2;
    if (startElement < endElement)
    {

        temp = arr[startElement + 1];
        arr[startElement + 1] = arr[startElement];

        for (counter = startElement + 1; counter <= endElement - 1; counter++)
        {
            temp2 = arr[counter + 1];
            arr[counter + 1] = temp;
            temp = temp2;
        }

        arr[startElement] = temp;
        return ES_OK;
    }
}
ES_t showArray(uint32 arr[], uint32 size)
{
    ES_t errorstate = ES_NOK;
    uint32 counter;
    for (counter = 0; counter < size; counter++)
    {
        printf("%d\t", arr[counter]);
        errorstate = ES_OK;
    }
    printf("\n");
    return errorstate;
}

/*************************************** END HELPING FUNCTION **********************************/

/*************************************** START PROGRAMS ****************************************/

ES_t sorting_By_Bubble(int arr[], int size)
{
    ES_t errorstate = ES_NOK;
    uint32 counter1, counter2;
    for (counter2 = 0; counter2 < size - 1; counter2++)
    {
        for (counter1 = 0; counter1 < size; counter1++)
        {
            if (arr[counter1] > arr[counter1 + 1])
            {
                swap_Helper(&arr[counter1], &arr[counter1 + 1]);
            }
        }
    }
}
ES_t sorting_By_Bubble_secursive(int arr[], int size)
{
    ES_t errorstate = ES_NOK;
    uint32 counter1;

    if (size == 0) // TO BREAK
        return ES_OK;

    for (counter1 = 0; counter1 < size - 1; counter1++)
    {

        // for (counter1 = 0; counter1 < size ; counter1++)
        // {
        if (arr[counter1] > arr[counter1 + 1])
        {
            swap_Helper(&arr[counter1], &arr[counter1 + 1]);
        }
        // }
    }
    sorting_By_Bubble_secursive(arr, size - 1);
}

ES_t sorting_By_Selection(int arr[], int size)
{
    ES_t errorstate = ES_NOK;
    uint32 counter1, posIndex, minIndex;
    for (posIndex = 0; posIndex < size - 1; posIndex++)
    {
        minIndex = posIndex; // select the postion

        for (counter1 = posIndex + 1; counter1 < size; counter1++) // find the minimun
        {
            if (arr[counter1] < arr[minIndex])
                minIndex = counter1;
        }
        swap_Helper(&arr[posIndex], &arr[minIndex]);

        errorstate = ES_OK;
    }
    return errorstate;
}
ES_t sorting_By_Insertion(int arr[], int size)
{
    ES_t errorstate = ES_NOK;
    uint32 counter1, posIndex;
    for (posIndex = 1; posIndex < size; posIndex++)
    {
        for (counter1 = 0; counter1 < posIndex; counter1++) // find the minimun
        {
            if (arr[counter1] > arr[posIndex])
            {
               
                move_Right_Helper(arr, counter1, posIndex);
                showArray(arr, 10);

                break;
            }
        }
        // printf("f \n");

        errorstate = ES_OK;
    }
    return errorstate;
}

/*************************************** END PROGRAMS **********************************************/

/************************************************************************************************
 * AUTHOR              DATE                    BRIEF
 ************************************************************************************************
 * TAREK ALLAM         16 NOV 2022             write programs
 *
 */