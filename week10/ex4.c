#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAXN 1000
#define MAXSTRING 1000

typedef struct 
{
	int inode;
	int n;
	char name[MAXN][MAXSTRING];	
} node;

node nodes[MAXN];
int m = 0;

int main ()
{
	DIR *dirp = opendir("../week10/tmp");
	struct dirent* dp;

	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp -> d_name[0] == '.')
			continue;
		
		struct stat st;
		stat(dp -> d_name, &st);
		
		if (st.st_nlink < 2)
			continue;
		
		int flag = 1;
		for (int i = 0; i < m; ++i)
			if (nodes[i].inode == st.st_ino)
			{
				strcpy(nodes[i].name[nodes[i].n], dp -> d_name);
				nodes[i].n++;			
				flag = 0;			
			}
		if (flag)
		{
			nodes[m].inode = st.st_ino;
			strcpy(nodes[m].name[nodes[m].n], dp -> d_name);
			nodes[m].n++;						
			m++;		
		}
	}

	closedir(dirp);
	printf("%d i-nodes with a hard link count of two or more\n", m);
	for (int i = 0; i < m; ++i)
	{
		printf("i-node number: %d\n%d files: ", nodes[i].inode, nodes[i].n);
		for (int j = 0; j < nodes[i].n; ++j)
			printf("%s, ", nodes[i].name[j]);
		printf("\n");
	}
	return 0;
}
