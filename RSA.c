#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
 
long int p,q,n,z,flag,e[100],d[100],temp[100],j,m[100],c[100],i;
 
char msg[100];
 
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();
 
void main() {
 	printf("========== RSA Encrypt and Decrypt ==========");
 	
 	// choosing of prime numbers p and q
	printf("\nENTER FIRST PRIME NUMBER p\n");
	scanf("%d",&p);
 
	flag=prime(p);
 
	if(flag==0) {
		printf("\nWRONG INPUT\n");
		getch();
		exit(1);
	}
 
	printf("\nENTER PRIME NUMBER q\n");
	scanf("%d",&q);
 
	flag=prime(q);
 
	if(flag==0||p==q) {
		printf("\nWRONG INPUT\n");
		getch();
		exit(1);
	}
 
	printf("\nENTER MESSAGE\n");
	fflush(stdin);
	gets(msg);
	
	for (i=0;msg[i]!=NULL;i++){
		m[i]=msg[i];
		n=p*q;
		z=(p-1)*(q-1);
	}
	
 	ce();
 	
	printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
 
	for (i=0;i<j-1;i++){
		printf("\n%ld\t%ld",e[i],d[i]);
	}
 
	encrypt();
	decrypt();
	getch();
 
}
 
int prime(long int pr) {
	int i;
	j=sqrt(pr);
	int retval=1;
 
	for (i=2;i<=j;i++) {
		if(pr%i==0){
			retval=0;
		}
	}
	return retval;
}
 
void ce() {
 
	int k=0;
 
	for (i=2;i<z;i++) {
 
		if(z%i==0){
			continue;
		}
		flag=prime(i);
 
		if(flag==1&&i!=p&&i!=q) {
			e[k]=i;
			flag=cd(e[k]);
			if(flag>0){
				d[k]=flag;
				k++;
			}
			if(k==99){
				break;
			}
 		}
	}
 
}

 
long int cd(long int x) {
 
	long int k=1;
 
	while(1) {
		k=k+z;
 
		if(k%x==0){
			return(k/x);
		}
	}
 
}
 
void encrypt() {
 	printf("\n===== ENCRYPTION AREA =====\n");
	long int pz,cz,key=e[0],k,len;
 
	i=0;
 
	len=strlen(msg);
 
	while(i!=len) {
		pz=m[i];
		pz=pz-96;
		k=1;
 
		for (j=0;j<key;j++) {
			k=k*pz;
			k=k%n;
		}
 
		temp[i]=k;
		cz=k+96;
		c[i]=cz;
		i++;
	}
 
	c[i]=-1;
	printf("\nTHE ENCRYPTED MESSAGE IS\n");
 
	for (i=0;c[i]!=-1;i++){
		printf("%c",c[i]);
	}
	printf("\n=== END OF ENCRYPTION AREA ===\n");
}
 
void decrypt() {
 	printf("\n===== DECRYPTION AREA =====\n");
	long int pz,cz,key=d[0],k;
 
	i=0;
 
	while(c[i]!=-1) {
		cz=temp[i];
		k=1;
		for (j=0;j<key;j++) {
			k=k*cz;
			k=k%n;
		}
 
		pz=k+96;
		m[i]=pz;
		i++;
	}
 
	m[i]=-1;
 
	printf("\nTHE DECRYPTED MESSAGE IS\n");
 
	for (i=0;m[i]!=-1;i++){
		printf("%c",m[i]);
	}
	printf("\n=== END OF DECRYPTION AREA ===\n");
}
