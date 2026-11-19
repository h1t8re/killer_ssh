#include <stdio.h>
#include "./include/stdlib.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
        const char *spliter_new_line = "\n\0";
        const char *spliter_by_space = " \0";
	char **line;
	char **word;
        int i = 0;
        int j = 0;
        while(1)
        {
                system("echo \"$(ps aux | grep ssh)\" > ./log_killer_ssh\0");
                const char *data = read_file_v1("./log_killer_ssh\0");
                line = strsplit_v1(data, spliter_new_line);
                while(line[i] != '\0')
                {
		      	if(strcontains(strdup(line[i]), strdup("killer_ssh\0")) == 0)
                        {
				i++;
			        continue;
                        }
			word = strsplit_v1(line[i], spliter_by_space);
                        while(word[j] != '\0')
                        {
				if(atoi(word[j]) != 0)
                                {
                                        printf("Killing process with pid '%d' ...", atoi(word[j]));
					kill(atoi(word[j]), SIGKILL);
					printf("[done]\n");
                                        break;
                                }
                                j++;
                        }
                        j = 0;
                        i++;
                }
                i = 0;
        }
        return 0;
}
