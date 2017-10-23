#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>



int main() {
	setlocale(LC_ALL, "Rus");

	int flag_menu = 0;
	char simvol;
	int index = 0;
	int flag = 1;
	char simvol_f;
	int index_2 = 0;
	int flag_2 = 0;
	int stroki = 0;
	do {
		printf("\n Введите номер задания \n");
		scanf_s("%d", &flag_menu);

		if (flag_menu == 1) {
			FILE *fp;
			fopen_s(&fp, "file1.txt", "r+");
			if (fp != NULL) {
				printf("\n Введите поисковой символ :\n");
				while (getchar() != '\n');
				scanf_s("%c",&simvol);

				fseek(fp, 0, SEEK_SET);
				
				while (flag!=0) {
					fseek(fp, index, SEEK_SET);
					fscanf_s(fp, "%c", &simvol_f);
					if (feof(fp) == true) {
						flag = 0;
						break;
					}
					if (simvol == simvol_f && flag_2==0) {
											index_2++;
											index++;
											flag_2 = 1;

										}
					else {
						flag_2 = 1;
						index++;
					}

					if (flag_2 == 1 && simvol_f==' ') {
						
						flag_2 = 0;
						
					}
					
					
				}
				printf("\n Количество слов начинающихся с этого символа = %d ", index_2);


				fclose(fp);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}
			

		}


		if (flag_menu == 2) {
			FILE *fp;
			fopen_s(&fp, "file1.txt", "r+");
			flag = 1;
			if (fp != NULL) {
				char buffer[100];
				printf("\nДан текст : \n");
				while (flag != 0) {
					if (fgets(buffer, 100, fp) != NULL) {
						puts(buffer);
					}
					else {
						flag = 0;
					}
				}

				FILE *fp_2;
				index = 0;
				fopen_s(&fp_2, "file2.txt", "w");
				if (fp_2 != NULL) {
					fseek(fp, 0, SEEK_SET);
					fseek(fp_2, 0, SEEK_SET);
					flag = 1;
					while (flag != 0) {
						
						fseek(fp, index, SEEK_SET);
						fscanf_s(fp, "%c", &simvol_f);
						if (feof(fp) == true) {
													flag = 0;
													break;
												}



						if (simvol_f == '0') {
							simvol_f = '1';
						}
						else if (simvol == '1') {
							simvol_f = '0';
						}
						fprintf(fp_2, "%c", simvol_f);
						index++;
					}
					fclose(fp_2);
				}
				else {
					printf("\n Невозможно открыть файл\n ");
				}




				fclose(fp);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}
			flag = 1;
			FILE *fp_3;
			fopen_s(&fp_3, "file2.txt", "r+");
			if (fp_3 != NULL) {
				fseek(fp_3, 0, SEEK_SET);
				char buffer[100];
				printf("\nПолученый текст : \n");
				while (flag != 0) {
					if (fgets(buffer, 100, fp_3) != NULL) {
						puts(buffer);
					}
					else {
						flag = 0;
					}
				}
				fclose(fp_3);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}

		}


		if (flag_menu == 3) {
			int mass[10] = { 1,2,3,4,5,6,7,8,9,10 };
			FILE *fp;
			fopen_s(&fp, "file2.txt", "w");
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				for (int i = 0; i < 10; i++) {
					fprintf(fp, "%d \n", mass[i]);
				}

				fclose(fp);

			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}
			flag = 1;
			fopen_s(&fp, "file2.txt", "r");
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				char buffer[100];
				printf("\nДан текст : \n");
				while (flag != 0) {
					if (fgets(buffer, 100, fp) != NULL) {
						puts(buffer);
					}
					else {
						flag = 0;
					}
				}
				fclose(fp);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}
		}


		if (flag_menu == 4) {
			FILE *fp;
			fopen_s(&fp, "file1.txt", "r+");
			flag = 1;
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				char buffer[100];
				printf("\nДан текст : \n");
				while (flag != 0) {
					if (fgets(buffer, 100, fp) != NULL) {
						puts(buffer);
					}
					else {
						flag = 0;
					}
				}
				fclose(fp);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}
			
			index_2 = 0;
			index = 0;
			fopen_s(&fp, "file1.txt", "r");
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				
				flag = 1;
				while (flag != 0) {

					fseek(fp, index, SEEK_SET);
					fscanf_s(fp, "%c", &simvol_f);
					if (feof(fp) == true) {
						flag = 0;
						break;
					}
					index_2++;
					index++;

					
				}
				fclose(fp);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}
			printf("\n Количество символов в тексте : %d \n", index_2);

		}

		if (flag_menu == 5) {
			FILE *fp;
			fopen_s(&fp, "file1.txt", "r+");
			flag = 1;
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				char buffer[100];
				printf("\nДан текст : \n");
				while (flag != 0) {
					if (fgets(buffer, 100, fp) != NULL) {
						stroki++;
						puts(buffer);
					}
					else {
						flag = 0;
					}
				}
				fclose(fp);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}
			printf("\n Количество строк в тексте : %d \n", stroki);
		}

		if (flag_menu == 6) {
			int id_stroki = 0;
			int size_stroki = 0;
			index = 0;
			FILE *fp;
			fopen_s(&fp, "file1.txt", "r+");
			flag = 1;
			char buffer[100];
			char buffer_2[100];
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				
				printf("\nДан текст : \n");
				size_stroki = 0;
				while (flag != 0) {
					if (fgets(buffer, 100, fp) != NULL) {
						
						if (strlen(buffer) >= size_stroki) {
							size_stroki = strlen(buffer);
							
							id_stroki = index;
							for (int i = 0; i < size_stroki; i++) {
								buffer_2[i] = buffer[i];
							}
							buffer_2[size_stroki] = '\0';
						}

						index++;
						puts(buffer);
					}
					else {
						flag = 0;
					}
				}
				fclose(fp);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}

			printf("Самая длинная строка : %s", buffer_2);
		}



		if (flag_menu == 7) {
			FILE *fp;
			char buffer_2[100];
			char buffer_3[100];
			char buffer_4[100];
			fopen_s(&fp, "file1.txt", "r+");
			flag = 1;
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				char buffer[100];
				printf("\nДан текст : \n");
				while (flag != 0) {
					if (fgets(buffer, 100, fp) != NULL) {
						puts(buffer);
					}
					else {
						flag = 0;
					}
				}
				fclose(fp);
			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}

			printf("\n Введите искоемое слово \n");
			while (getchar() != '\n');
			gets_s(buffer_2, 100);
			printf("\n Введите новое слово \n");
			while (getchar() != '\n');
			gets_s(buffer_3, 100);

			fopen_s(&fp, "file1.txt", "r+");
			flag = 1;
			index_2 = 0;
			if (fp != NULL) {
				fseek(fp, 0, SEEK_SET);
				do {
					fseek(fp, index, SEEK_SET);
					fscanf_s(fp, "%c", &simvol_f);
					if (feof(fp) == true) {
						flag = 0;
						break;
					}

					while (simvol_f != ' ') {
						buffer_4[index_2] = simvol_f;
						index_2++;
					}
					if (buffer_4 == buffer_2) {
						fprintf_s(fp, "%s", buffer_3);
						index = index + strlen(buffer_3);
					}

				} while (flag != 0);


			}
			else {
				printf("\n Невозможно открыть файл\n ");
			}


		}


	} while (flag_menu != 0);

}