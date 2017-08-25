#include <stdio.h>

#define MASSSINGLEMOLUCULE 3.0e-23
#define QUARTPERGRAMS 950

int main(){
		int quartsize;
		float moluecules;
		
		printf("Please enter the amount of water in quarts: \n");
		scanf("%d",&quartsize);
		moluecules=(QUARTPERGRAMS * quartsize)/MASSSINGLEMOLUCULE;
		printf("The number of water moluecules in that %d quarts of water is %e\n", quartsize, moluecules);
		
}