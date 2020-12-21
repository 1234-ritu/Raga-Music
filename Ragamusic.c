#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<string.h>
struct sll
{
	int data;
	struct sll *next;
};
typedef struct sll node;
node *head=NULL,*new,*temp,*prev;
int key;
int menu()
{
	int ch;
	printf("\n=========================================\n");
	printf("---------------RAGA MUSIC---------------\n");
	printf("=========================================\n");
	printf("1.Create playlist\n2.Add song in the beginning\n3.Add song in the end");
	printf("\n4.Add song at a position\n5.Delete song in the beginning\n6.Delete song in the end\n7.Delete song at a position");
	printf("\n8.Display playlist\n9.Play songs\n10.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
    return(ch);
}
void play(char path[])
{
	long int a;
	while(1)
	{
		PlaySound(TEXT(path),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        printf("0.EXIT\n1.Restart\n2.Next song\n");
        scanf("%d",&a);
        system("CLS");
        if(a==0)
        {
        	exit(0);
		}
		else if(a==1){
			PlaySound(0,0,0);
			printf("To restart music:");
			system("pause");
		}
		else if(a==2)
		{
			break;
		}
		else
		{
			printf("Invalid input");
		}
	}
}
void create()
{
    system("CLS");
	if(head==NULL)
	{
		printf("Songs list:\n");
	    printf("1.Its OK if you forget Me-Astrid S\n");
	    printf("2.A different way-DJ Snake ,Lauv\n");
	    printf("3.See you again-wiz Khalifa\n");
	    printf("4.Confident-Demi Lovato\n");
	    printf("5.Ruin my life-Zara Larrson\n");
		new=(node*)malloc(sizeof(node));
		printf("Enter the song number:");
		scanf("%d",&new->data);
		new->next=NULL;
		head=new;
	}
	else
	{
		printf("Playlist already exists\n");
	}
	sleep(2);
	system("CLS");
}
void insert_beg()
{
	system("CLS");
	printf("Songs list:\n");
	printf("1.Its OK if you forget Me-Astrid S\n");
	printf("2.A different way-DJ Snake ,Lauv\n");
	printf("3.See you again-wiz Khalifa\n");
	printf("4.Confident-Demi Lovato\n");
	printf("5.Ruin my life-Zara Larrson\n");
	new=(node *)malloc(sizeof(node));
	printf("Enter the song number:");
	scanf("%d",&new->data);
	new->next=head;
	head=new;
	sleep(2);
	system("CLS");
}
void insert_end()
{
	system("CLS");
	printf("Songs list:\n");
	printf("1.Its OK if you forget Me-Astrid S\n");
	printf("2.A different way-DJ Snake ,Lauv\n");
	printf("3.See you again-wiz Khalifa\n");
	printf("4.Confident-Demi Lovato\n");
	printf("5.Ruin my life-Zara Larrson\n");
	new=(node*)malloc(sizeof(node));
	printf("Enter the song no.:");
	scanf("%d",&new->data);
	new->next=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new;
	sleep(2);
	system("CLS");
}
void insert_middle()
{
	system("CLS");
	printf("Songs list:\n");
	printf("1.Its OK if you forget Me-Astrid S\n");
	printf("2.A different way-DJ Snake ,Lauv\n");
	printf("3.See you again-wiz Khalifa\n");
	printf("4.Confident-Demi Lovato\n");
	printf("5.Ruin my life-Zara Larrson\n");
	printf("Enter the song no. after which new song to be inserted:");
	scanf("%d",&key);
	new=(node *)malloc(sizeof(node));
	printf("Enter the song no.:");
	scanf("%d",&new->data);
	temp=head;
	while(temp->data!=key)
	{
		temp=temp->next;
	}
	new->next=temp->next;
	temp->next=new;
	sleep(2);
	system("CLS");
}
void delete_beg()
{
	temp=head;
	head=head->next;
	free(temp);
}
void delete_end()
{
	temp=head;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
}
void delete_middle()
{
	temp=head;
	printf("Enter the song to be deleted from the playlist:");
	scanf("%d",&key);
	while(temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data == 1)
		{
			printf("Its OK if you forget about me-Astrid S\n");
		}
		else if(temp->data == 2)
		{
			printf("A different way-DJ Snake,Lauv\n");
		}
		else if(temp->data ==3)
		{
			printf("See you again ft.charlie puth-Wiz khalifa\n");
		}
		else if(temp->data == 4)
		{
			printf("Confident-Demi Lovato\n");
		}
		else
		{
			printf("Ruin my life-Zara Larson\n");
		}
		temp=temp->next;
	}
}
int main()
{
	int ch;
	//Paths of the song files
	char path1[]="C:\\Users\\91991\\Documents\\RagaMusic\\Music library\\song1.wav";
	char path2[]="C:\\Users\\91991\\Documents\\RagaMusic\\Music library\\song2.wav";
	char path3[]="C:\\Users\\91991\\Documents\\RagaMusic\\Music library\\song3.wav";
	char path4[]="C:\\Users\\91991\\Documents\\RagaMusic\\Music library\\song4.wav";
	char path5[]="C:\\Users\\91991\\Documents\\RagaMusic\\Music library\\song5.wav";
	system("color 4f");
    do
	{
		system("ClS");
		ch=menu();
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				
				insert_beg();
				break;
			case 3:
				insert_end();
				break;
			case 4:

				insert_middle();
				break;
			case 5:
				delete_beg();
				printf("Playlist after deleting:\n");
	            display();
	            sleep(3);
	            system("CLS");
				break;
			case 6:
				delete_end();
				printf("Playlist after deleting:\n");
	            display();
	            sleep(3);
	            system("CLS");
				break;
			case 7:
				delete_middle();
				printf("Playlist after deleting:\n");
	            display();
	            sleep(3);
	            system("CLS");
				break;
			case 8:
				system("CLS");
				printf("--------------------------------------\n");
				printf("---------------Playlist---------------\n");
				printf("--------------------------------------\n");
				display();
				sleep(5);
	            system("CLS");
				break;
			case 9:
				system("CLS");
				temp=head;
				system("color 3f");
				while(temp!=NULL)
				{
					if(temp->data == 1)
					{
						printf("Song Name:Its OK if you forget Me\n");
						printf("Song artist:Astrid S\n");
						play(path1);
					}
					else if(temp->data ==2)
					{
						printf("Song Name:A different way\n");
	                    printf("Song artist:DJ Snake, Lauv\n");
	                    play(path2);
					}
					else if(temp->data == 3)
					{
						printf("Song Name:See you agian\n");
	                    printf("Song artist:Wiz Khalifa\n");
	                    play(path3);
					}
					else if(temp->data == 4)
					{
						printf("Song Name:Confident\n");
	                    printf("Song artist:Demi Lovato\n");
	                    play(path4);
					}
					else
					{
						printf("Song Name:Ruin my life\n");
	                    printf("Song artist:Zara Larrson\n");
	                    play(path5);
					}
					temp=temp->next;
				}
			case 10:
				break;
			default:
				printf("\nEnter a valid choice(1-10)\n");
				break;
		}
	}while(ch!=10);
	return 0;
}
