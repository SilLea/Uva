//#include<stdio.h>
//#include<string.h>
//#include<ctype.h>
//char ch2[100000],ch1[100000];
//int main(void)
//{
//	while (scanf("%s%s", ch1, ch2) != EOF) 
//	{
//		int i, j = 0;
//		int len1 = strlen(ch1);
//		int len2 = strlen(ch2);
//		for (i = 0, j = 0; i < len1; i++)
//		{
//			for (; j <= len2;)
//			{
//				if (ch1[i] != ch2[j])
//					j++;
//				else 
//				{
//					j++;
//					break;
//				}
//			}
//			if (j > len2)break;
//		}
//		if (j <= len2 && i==len1)
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//}