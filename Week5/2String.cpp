
/*  @name 4BST.cpp
    @desc
    2. Write a menu driven Program using function to concatenate, compare, find length, convert to lower/upper case strings using
    pointers.

   Prototypes : a. int StrLen(char S[]);                                  b. void StrCpy(char S[], char T[]);
                c. int StrCmp(char S[], char T[]);             d. void StrCat(char S[],char T[]);
                e. void ToUpper(char S[]);                        f. void ToLower(char S[]);
    @author Ankit Apurv 180970042
    @date 06/01/2019
*/

#include <iostream>
using namespace std;

/*  @desc counts string length
    @args
       char[] string
    @return int length
*/
int StrLen(char S[])
{
	int length=0;
	while(S[length] != '\0')
		length++;
	return length;
}

/*  @desc convert english alphabets to uppercase
    @args
       char[] string
    @return void
*/
void ToUpper(char S[])
{
	int i=0;
	while(S[i] != '\0')
	{
		if(S[i]>=97 && S[i]<=122)
			S[i] -= 32;
		i++;
	}
	return;
}

/*  @desc convert english alphabets to lowercase
    @args
       char[] string
    @return void
*/
void ToLower(char S[])
{
	int i=0;
	while(S[i] != '\0')
	{
		if(S[i]>=65 && S[i]<=90)
			S[i] += 32;
		i++;
	}
	return;
}

/*  @desc compare two strings
    @args
       char[] string first
       char[] string second
    @return int ASCII difference first-second
*/
int StrCmp(char S[], char T[])
{
	int s=0, t=0, i=0;
	while(S[i] != '\0')
		s += S[i++];
	i=0;
	while(T[i] != '\0')
		t += T[i++];
	return s-t;
}

/*  @desc append second string to first
    @args
       char[] string first
       char[] string second
    @return void
*/
void StrCat(char S[],char T[])
{
	int s=0, t=0, i=0;
	while(S[i] != '\0')
		s += S[i++];
	s += 1;//'\0'
	i=0;
	while(T[i] != '\0')
		t += T[i++];
	t += 1;//'\0'
	int size = s+t-1;//2 time '\0'

	char U[size];
	i=0, s=0, t=0;
	while(S[s] != '\0')
		U[i++] = S[s++];
	while(T[t] != '\0')
		U[i++] = T[t++];
	U[++i] = '\0';
	S = U;
	return;
}

/*  @desc copy contents of first string to second
    @args
       char[] string first
       char[] string second
    @return void
*/
void StrCpy(char S[], char T[])
{
	int i=0;
	do
	{
		T[i] = S[i];
		i++;
	} while(S[i] != '\0');
	return;
}

/*  @desc main
    @args
       void
    @return exitcode : int 0
*/
int main(void)
{
	char S[5], T[5];
	for(int i=0; i<=3; i++)
		cin >> S[i];
	StrCpy(S, T);
	cout << T << '\n';
	cout << StrCmp(S, T) << '\n';
	ToLower(S);
	cout << S << '\n';
	ToUpper(S);
	cout << S << '\n';
	cout << "String length : " << StrLen(S) << '\n';
	StrCat(S, T);
	cout << S << '\n';
	return 0;
}