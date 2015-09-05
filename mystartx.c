#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>



int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stdout,"\033[1;31m pass an argument: %s <session>\033[0m \n\n",argv[0]);
		return -1;
	}
	
	
	const char *user_dir = getpwuid(getuid())->pw_dir; //.pw_dir;//pw->pw_dir;
	const char *xinitrc = "/.xinitrc";
	
	char user_xinitrc [strlen(user_dir) + strlen(xinitrc)+1];

	strcpy(user_xinitrc,user_dir);
	strcat(user_xinitrc,xinitrc);


	FILE *file = fopen(user_xinitrc,"w");

	if(file == NULL)
	{
		fprintf(stdout,"\033[0;31m Error Creating File .xinitrc\033[0m\n\n");
		return 1;
	
	}
	 // comentario adicionado.

	fwrite(argv[1], sizeof(char), strlen(argv[1]), file);

	fclose(file);
	
	system("startx");


	
	return 0;
}




