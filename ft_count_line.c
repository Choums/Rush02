#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int	file;
    int totalLinesCount = 0;
    char c;

    file = open("numbers.dict", O_RDONLY);
    if(file == -1){
        printf("The file doesn't exist ! Please check again .");
        return 0;
    }  
    while(read(file, &c, 1) > 0)
	{
        if(c == '\n'){
            totalLinesCount ++;
        }
    }
    close(file);
    totalLinesCount ++;
    printf("Total number of lines are : %d\n",totalLinesCount);
    return 0;
}
