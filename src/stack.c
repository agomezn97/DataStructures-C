#include "datastructs.h"

struct StackStruct {
    int  length;
    int *base;
    int *head;
};

/* Check if pointers are valid */
static StackStatus_e Stack_Check(Stack_t buffer)
{
    if ( ! buffer || ! buffer->head || ! buffer->base ) {
        return STACK_NULL;
    }
    return STACK_OK;
}

StackStatus_e Stack_Init(Stack_t buffer, int length) 
{
    buffer = malloc(sizeof(int)*3);
    buffer->length = length;
    buffer->base = malloc(sizeof(int) * length);
    if ( ! buffer->base ) { return STACK_INIT_ERROR; }
    buffer->head = buffer->base;
    return STACK_OK;
}

StackStatus_e Stack_Is_Full(Stack_t buffer)
{
    // Check for errors:
    StackStatus_e status = Stack_Check(buffer);
    if (status != STACK_OK) 
        return STACK_NULL;

    if (buffer->head >= (buffer->base + buffer->length)) 
        return STACK_FULL;
    else 
        return STACK_NOT_FULL;
}

StackStatus_e Stack_Is_Empty(Stack_t buffer)
{
    // Check for errors:
    StackStatus_e status = Stack_Check(buffer);
    if (status != STACK_OK) 
        return STACK_NULL;

    if (buffer->base == buffer->head) 
        return STACK_EMPTY;
    else 
        return STACK_NOT_EMPTY;
}

StackStatus_e Stack_Push(Stack_t buffer, int item2push) 
{
    // Check if buffer is full: (refactorizar)
    StackStatus_e fullCheck = Stack_Is_Full(buffer);
    if ( Stack_Is_Full(buffer) != STACK_NOT_FULL ) 
        return fullCheck;
        
    *(buffer->head) = item2push; 
    buffer->head++;
    return STACK_OK;
}

StackStatus_e Stack_Pop(Stack_t buffer, int *item2pop)
{
    // Check if buffer is empty: (refactorizar)
    StackStatus_e emptyCheck = Stack_Is_Empty(buffer);
    if ( Stack_Is_Empty(buffer) != STACK_NOT_EMPTY ) 
        return emptyCheck;

    buffer->head--;
    *item2pop = *(buffer->head);
    return STACK_OK;
}

StackStatus_e Stack_Delete(Stack_t buffer)
{
    free(buffer->base);
}