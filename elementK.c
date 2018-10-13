#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int totalRecord = 0;
	int pageSize = 0;
	int pageIndex = 0;
	int numberPerPage = 3;
	printf("Input total record: ");
	scanf_s("%d", &totalRecord);
	printf("\nInput page size: ");
	scanf_s("%d", &pageSize);
	printf("\nInput page index: ");
	scanf_s("%d", &pageIndex);
	int totalPage = (totalRecord / pageSize) + (totalRecord % pageSize > 0);
	printf("Total Page: %d\n", totalPage);
	int record = pageSize * (pageIndex - 1) + 1;
	int i = 1;
	while (i <= pageSize && record <= totalRecord)
	{
		printf("Record %d\n", record);
		record++;
		i++;
	}
	int numberPage = pageIndex - (numberPerPage / 2);
	if (numberPage > totalPage - numberPerPage + 1)
		numberPage = totalPage - numberPerPage + 1;
	if (totalPage <= numberPerPage)
		numberPage = 1;
	i = 1;
	printf("Page:");
	while (i <= numberPerPage && numberPage <= totalPage)
	{
		printf("[%d] ", numberPage);
		numberPage++;
		i++;
	}

}
