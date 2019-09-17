#include<stdio.h>

typedef struct node{
	char data;
	int left;
	int right;
}NODE;

NODE tree[26];

void preorder(int a){
	if(a != -1){
		printf("%c",tree[a].data);
		preorder(tree[a].left);
		preorder(tree[a].right);
	}
	else return;
}

void inorder(int a){
	if(a != -1){
		
		inorder(tree[a].left);
		printf("%c",tree[a].data);
		inorder(tree[a].right);
	}
	else return;
}

void postorder(int a){
	if(a != -1){
		
		postorder(tree[a].left);
		postorder(tree[a].right);
		printf("%c",tree[a].data);
	}
	else return;
}


int main(){
	//freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	getchar();
	
	
	char a,b,c;
	for(int i=0;i<n;i++){
		scanf("%c %c %c",&a,&b,&c);
		getchar();
		//printf("%c %c %c",a,b,c);
		tree[(int)(a-'A')].data = a;
		if(b != '.'){
			tree[(int)(a-'A')].left = (int)(b - 'A');
		}
		else
			tree[(int)(a-'A')].left = -1;
		if(c != '.'){
			tree[(int)(a-'A')].right = (int)(c - 'A');
		}
		else
			tree[(int)(a-'A')].right = -1;
	}
	
	int root = 0;
	preorder(root);
	printf("\n");
	
	inorder(root);
	printf("\n");
	
	postorder(root);
}
