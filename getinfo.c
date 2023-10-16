#include "shell.h"

/**
 * initializeInfo - initializes info_t struct
 * @info: struct address
 */
void initializeInfo(info_t *info)
{
	info->arguments = NULL;
	info->argumentsVector = NULL;
	info->executablePath = NULL;
	info->argumentCount = 0;
}

/**
 * configureInfo - initializes info_t struct
 * @info: struct address
 * @argumentVector: argument vector
 */
void configureInfo(info_t *info, char **argumentVector)
{
	int i = 0;

	info->filename = argumentVector[0];

	if (info->arguments)
	{
	info->argumentsVector = tokenizeString(info->arguments, " \t");

	if (!info->argumentsVector)
	{
	info->argumentsVector = malloc(sizeof(char *) * 2);

		if (info->argumentsVector)
            
	info->argumentsVector[0] = duplicateString(info->arguments);
	info->argumentsVector[1] = NULL;
	}
	}

        for (i = 0; info->argumentsVector && info->argumentsVector[i]; i++)

	info->argumentCount = i;

	replaceAliases(info);
	replaceVariables(info);
	}
}

/**
 * releaseInfo - frees info_t struct fields
 * @info: struct address
 * @freeAll: true if freeing all fields
 */
void releaseInfo(info_t *info, int freeAll)
{
	free(info->argumentsVector);
	info->argumentsVector = NULL;
	info->executablePath = NULL;
	
	if (freeAll)
	{
	if (!info->commandBuffer)
	{
	free(info->arguments);
	}

	if (info->environment)
	{
	freeList(&(info->environment));
	}

	if (info->history)
	{
	freeList(&(info->history));
	}

	if (info->aliasList)
	{
	freeList(&(info->aliasList));
	}

	free(info->environmentArray);
	info->environmentArray = NULL;

	bulkFree((void **)info->commandBuffer);

	if (info->readFileDescriptor > 2)
	{
	close(info->readFileDescriptor);
	}

	_putchar(BUF_FLUSH);
	}
}
