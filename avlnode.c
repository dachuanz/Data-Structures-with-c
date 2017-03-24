#include <stdio.h>
#include <stdlib.h>//使用GCC 5.4 测试
#define LENGTH(a) ((sizeof(a))/(sizeof(a[0])))



#define HEIGHT(node) ((node==NULL) ? 0 :(((avlnode *)(node))->height))
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef int elementType;
typedef struct node {
	elementType key;
	struct node *left;
	struct node *right;
	int height;//当前结点深度
} avlnode,*avltree;
int getNode_height(avlnode *node);//获取当前结点的深度

avlnode *create_node(elementType key,avlnode *left,avlnode *right);//创建结点

avlnode *maximun_node(avltree tree);//求树中最大结点

avlnode *minimun_node(avltree tree);//求树中最小结点

avltree  avltree_insertNode(avltree tree,elementType key);//向树中插入结点

avltree  avltree_deleNode(avltree tree,elementType key);//删除结点

void pre_order_avltree(avltree tree);//前序遍历

void in_order_avltree(avltree tree);//中序遍历

void post_order_avltree(avltree tree);//后序遍历

void print_avltree(avltree tree, elementType key, int direction);//打印树的信息

avlnode *search_node(avltree tree,elementType key);//根据key 的值搜索结点






int getNode_height(avlnode *node) {
	return HEIGHT(node);
}

avlnode *create_node(elementType key,avlnode *left,avlnode *right) {
	avlnode *node=(avlnode *)malloc(sizeof(avlnode));
	if(node==NULL) {
		printf("创建结点失败");
		return NULL;
	}
	node->key=key;
	node->left=left;
	node->right=right;
	node->height=0;

	return node;
}

avlnode *  maximun_node(avltree tree) {
	if(tree==NULL)
	{return NULL;}
	while(tree->right)
	{tree=tree->right;}
	return tree;
}

avlnode *minimun_node(avltree tree) {
	if(tree==NULL)
		return NULL;
	while(tree->left)
		tree=tree->left;

	return tree;
}
/**
先序遍历
*/
void pre_order_avltree(avltree tree) {
	if(tree) {
		printf("%d\n",tree->key);
		pre_order_avltree(tree->left);
		pre_order_avltree(tree->right);
	}
	else{
			printf("无节点\n");
	}
}

void in_order_avltree(avltree tree) {
	if(tree) {
		in_order_avltree(tree->left);
		printf("%d\n",tree->key);
		in_order_avltree(tree->right);

	}
}

void post_order_avltree(avltree tree) {
	if(tree) {
		post_order_avltree(tree->left);
		post_order_avltree(tree->right);
		printf("%d    ",tree->key);

	}
}

static avltree left_left_rotation(avltree tree) {
	avlnode *k2=tree->left;
	tree->left=k2->right;
	k2->right=tree;
	//！！！！切记所有旋转操作后要重新调整树的高度
	tree->height=MAX(getNode_height(tree->left),getNode_height(tree->right))+1;
	k2->height=MAX(getNode_height(k2->left),getNode_height(k2->right))+1;
	return k2;
}


static avltree right_right_rotation(avltree tree) {
	avlnode *k3=tree->right;
	tree->right=k3->left;
	k3->left=tree;
	tree->height=MAX(getNode_height(tree->left),getNode_height(tree->right))+1;
	k3->height=MAX(getNode_height(k3->left),getNode_height(k3->right))+1;
	return k3;
}


static avltree left_right_rotation(avltree tree) {
	tree->left=right_right_rotation(tree->left);
	tree=left_left_rotation(tree);
	return tree;
}

static avltree right_left_rotation(avltree tree) {
	tree->right=left_left_rotation(tree->right);
	tree=right_right_rotation(tree);
	return tree;
}

/*
    插入结点操作类似二叉树搜索树，但是avl要在插入新结点后保证树的平衡性
 */
avltree  avltree_insertNode(avltree tree,elementType key) {
	if(tree==NULL) {
		avlnode *node=create_node(key,NULL,NULL);

		tree=node;

	} else if(key<tree->key) { //在左子树中插入结点
		tree->left=avltree_insertNode(tree->left,key);//递归寻找插入节点的位置

		//插入节点后可能引起二叉树的不平衡，所以要在此进行判断
		if(HEIGHT(tree->left)-HEIGHT(tree->right)==2) {
			//在这儿判断是LL还是LR
			if(key<tree->left->key) {
				//LL旋转
				tree= left_left_rotation(tree);

			} else {
				//LR旋转
				tree=left_right_rotation(tree);
			}
		}
	} else if(key>tree->key) { //在右子树中插入结点
		tree->right=avltree_insertNode(tree->right,key);
		if(getNode_height(tree->right)-getNode_height(tree->left)==2) {
			//RR旋转
			if(key>tree->right->key) {
				tree= right_right_rotation(tree);
			} else {
				//RL旋转
				tree=right_left_rotation(tree);
			}
		}
	} else {
		printf("不允许插入相同值结点");

	}
	//！！！重新调整二叉树的深度
	tree->height=MAX(getNode_height(tree->left),getNode_height(tree->right))+1;

	return tree;
}

/*
 * 打印"AVL树"
 *
 * tree       -- AVL树的节点
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
void print_avltree(avltree tree, elementType key, int direction) {
	if(tree != NULL) {
		if(direction==0)    // tree是根节点
			printf("%2d is root\n", tree->key, key);
		else                // tree是分支节点
			printf("%2d is %2d's %6s child\n", tree->key, key, direction==1?"right" : "left");

		print_avltree(tree->left, tree->key, -1);
		print_avltree(tree->right,tree->key,  1);
	}
}
/*

返回指向 avl树的指针
*/
avlnode *search_node(avltree tree,elementType key) {
	if(tree==NULL||tree->key==key) {
		return tree;
	} else if(key<tree->key) {
		search_node(tree->left,key);
	} else {
		search_node(tree->right,key);
	}
}
/*
删除avl中的结点  ------ 删除结点和二叉搜索树的策略类似，但关键是维护树的平衡性
*/
avltree  avltree_deleNode(avltree tree,elementType key) {
	avlnode *node =search_node(tree,key);
	if(tree==NULL||node==NULL) {
		return tree;
	}
	if(key<tree->key) { //要删除的结点在左子树
		//递归找到要删除的结点
		tree->left= avltree_deleNode(tree->left,key);
		//删完后要检查平衡性
		if(getNode_height(tree->right)-getNode_height(tree->left)==2) {
			if(key<tree->right->key) {
				tree=right_left_rotation(tree);//RL旋转
			} else {
				tree=right_right_rotation(tree);//RL旋转
			}
		}
	} else if(key>tree->key) { //要删除的结点在右子树
		tree->right= avltree_deleNode(tree->right,key);
		if(getNode_height(tree->left)-getNode_height(tree->right)==2) {
			if(key<tree->left->key) {
				tree=left_left_rotation(tree);//LL旋转
			} else {
				tree=left_right_rotation(tree);//LR旋转
			}

		}
	} else { //找到要删除的结点
		/*如果要删除的结点有两个孩子，删除策略同二叉搜索树，右子树中最小结点赋值给当前结点，
		并删除最小结点，这样保证了二叉树的有序性，下面再讨论二叉树的平衡性*/
		if(tree->left&&tree->right) {
			avlnode *min_node=minimun_node(tree->right);
			tree->key=min_node->key;
			tree->right= avltree_deleNode(tree->right,min_node->key);

		} else {
			tree=tree->left?tree->left:tree->right;//独子或者无子情况删除结点同儿茶搜索树
		}
	}
	if(tree)
	{
		tree->height=MAX(getNode_height(tree->left),getNode_height(tree->right))+1;
		}
	return tree;
}


int main() {
	avltree tree=NULL;
//	int a[]= {1,2,3,4,5,6,7,};
	int a[]={1,2,3,4,5,6,7};
	int length=LENGTH(a);
	int i ;
	for( i=0; i<length; i++) {
		tree=avltree_insertNode(tree,a[i]);
	}


	int max_height=getNode_height(tree);
	printf("树高度为：%d\n",max_height);
	printf("前序遍历：\n");
	pre_order_avltree(tree);

	printf("\n");
/**	printf("中序遍历：");
	in_order_avltree(tree);
	printf("\n");
	printf("后序遍历：");
	post_order_avltree(tree);
	printf("\n");

	printf("min=%d\n",minimun_node(tree)->key);
	printf("max=%d\n",maximun_node(tree)->key);
	print_avltree(tree,tree->key,0);


	printf("删除结点\n");
	tree=avltree_deleNode(tree,6);
	print_avltree(tree,tree->key,0);
	return 0;
*/
}
