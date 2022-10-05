#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
	FILE *fp,*ft;
	char another,choice;
	struct student
	{
		char first_name[50],last_name[50];
		char course[100];
		int section;
	};
	struct student e;
	char xfirst_name[50],xlast_name[50];
	long int recsize;
	fp=fopen("users.txt","rb+");
	if(fp==NULL)
	{
		fp=fopen("users.txt","wb+");
		if(fp==NULL)
		{
			puts("Cannot open file");
			return 0;
		}
	}
	recsize=sizeof(e);
	while(1)
	{
		system("cls");
		cout<<"\t\tSTUDENT DATABASE MANAGEMENT SYSTEM====";
		cout<<"\n\n\n\n";
		cout<<"\n\t\t1. Add Records";
		cout<<"\n\t\t2. List Records";
		cout<<"\n\t\t3. Modify Records";
		cout<<"\n\t\t4. Delete Records";
		cout<<"\n\t\t5. Exit Program";
		cout<<"\n\nSelect your choice";
		fflush(stdin);
		choice=getche();
		switch(choice)
		{
			case 1:
				fseek(fp,0,SEEK_END);
				another='Y';
				while(another=='Y'||another=='y')
				{
					system("cls");
					cout<<"Enter the First Name: ";
					cin>>e.first_name;
					cout<<"Enter the Last Name: ";
					cin>>e.last_name;
					cout<<"Enter the course: ";
					cin>>e.course;
					cout<<"Enter the Section: ";
					cin>>e.section;
					fwrite(&e,recsize,1,fp);
					cout<<"\nAdd another record(Y/N)";
					fflush(stdin);
					another=getchar();
				}
				break;
				case 2:
					system("cls");
					rewind(fp);
					cout<<"===View the records of the database===";
					cout<<"\n";
					while(fread(&e,recsize,1,fp)==1)
					{
						cout<<"\n";
						cout<<"\n"<<e.first_name<<setw(10)<<e.last_name;
						cout<<"\n";
						cout<<"\n"<<e.course<<setw(8)<<e.section;
					}
					cout<<"n\n";
					system("pause");
					break;
				case 3:
				    system("cls");
					another='Y';
				    while(another=='Y'||another=='y')
				    {
					    cout<<"\nEnter the last name of the student: ";
						cin>>xlast_name;
						rewind(fp);
						while(fread(&e,recsize,1,fp)==1)
					    {
						    if(strcmp(e.last_name,xlast_name)==0)
							{
								cout<<"Enter the First Name: ";
					            cin>>e.first_name;
					            cout<<"Enter the Last Name: ";
					            cin>>e.last_name;
					            cout<<"Enter the course: ";
					            cin>>e.course;
					            cout<<"Enter the Section: ";
					            cin>>e.section;
					            fseek(fp,recsize,SEEK_CUR);
					            fwrite(&e,recsize,1,fp);
					            break;
							}
							else
							    cout<<"record not found";
						
						}
						cout<<"\n Modify another record (Y/N))";
						fflush(stdin);
						another=getchar();			
		            }
		            break;
		        case 4:
				     system("cls");
					another='Y';
				    while(another=='Y'||another=='y')
				    {
	                    cout<<"\nEnter the last name of the student to delete: ";
						cin>>xlast_name;
						ft=fopen("temp.dat","wb");
						while(fread(&e,recsize,1,fp)==1)
					    {
						    if(strcmp(e.last_name,xlast_name)!=0)
							{	
							    fwrite(&e,recsize,1,fp);			     
	                        }
	                    }
	                    fclose(fp);
						fclose(ft);
						remove("users.txt");
						rename("temp.dat","users.txt");
						fp=fopen("users.txt","rb+");
						cout<<"delete another record (Y/N)";
						fflush(stdin);
						another=getchar();    
                    }
                    break;
                case 5:
				    fclose(fp);
					cout<<"\n\n";
					cout<<"\t\t Thank you for using this software";
					cout<<"\t\t";
					exit(0);
	    }
	}
	    system("pause");
	    return 0;
}
