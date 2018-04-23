/*************************************************************************
	> File Name: 1.cpp
	> Author: 刘嘉辉
	> Mail: 
	> Created Time: 2018年04月14日 星期六 16时31分41秒

    > 本代码 核心算法在 335 行

************************************************************************/


#include <iostream>
#include <fstream>
#include <algorithm>
#include <streambuf>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include "json.hpp"

using namespace std;
using json::JSON;


JSON getJsonFromFile(string path) 
{
    string json_content;
	ifstream input(path);
	input.seekg(0, ios::end);
	json_content.reserve(input.tellg());
	input.seekg(0, ios::beg);
	json_content.assign((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
	JSON json_data = JSON::Load(json_content);
	return json_data;
}

/*
 * 将数字转换为字符串
 */

string intToString(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

/*
 * 二叉树节点
 */

class BiTreeNode {

public:
	int val; //字典
	string index; //序数
	BiTreeNode* left;
	BiTreeNode* right;
	BiTreeNode(int v, string i, BiTreeNode* l = NULL, BiTreeNode* r = NULL) {
		val = v;
		index = i;
		left = l;
		right = r;
	}
};

/*
 * 依据JSON数据递归创建二叉树
 */
BiTreeNode* createTreeByJson(BiTreeNode* this_node, JSON tree_data, string index) 
{
	int value = tree_data[index]["value"].ToInt();
	string l_index = tree_data[index]["left"].ToString();
	string r_index = tree_data[index]["right"].ToString();

	this_node = new BiTreeNode(value, index, NULL, NULL);
	if (l_index != "") {
		this_node->left = createTreeByJson(this_node->left, tree_data, l_index);
	}
	if (r_index != "") {
		this_node->right = createTreeByJson(this_node->right, tree_data, r_index);
	}

	return this_node;
}


/*
 * 输出节点的值
 */
void printValue(BiTreeNode* root) 
{
	cout << root->val;
}


//前序遍历二叉树
void preOrderTravel(BiTreeNode* root) 
{
	if (root == NULL)
		return;
	printValue(root);
	preOrderTravel(root->left);
	preOrderTravel(root->right);
}


//中序遍历二叉树
void inOrderTravel(BiTreeNode* root) 
{
	if (root == NULL)
		return;
	inOrderTravel(root->left);
	printValue(root);
	inOrderTravel(root->right);
}


//后序遍历二叉树
void postOrderTravel(BiTreeNode* root) 
{
	if (root == NULL)
		return;
	postOrderTravel(root->left);
	postOrderTravel(root->right);
	printValue(root);

}


//层序遍历二叉树
void LevelOrderTravel(BiTreeNode* root) 
{
	if (root == NULL)
		return;
	queue<BiTreeNode*> q;
	q.push(root);
	while (q.empty() == false) {
		root = q.front();
		printValue(root);
		q.pop();
		if (root->left)
			q.push(root->left);
		if (root->right)
			q.push(root->right);
	}
}


//判断两棵二叉树是否相同
bool TreeStructCmp(BiTreeNode* root1, BiTreeNode* root2) 
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1->val != root2->val)
		return false;
	bool leftResult = TreeStructCmp(root1->left, root2->left);
	bool rightResult = TreeStructCmp(root1->right, root2->right);
	return leftResult && rightResult;
}



//递归生成json数组
void _treeToJson(BiTreeNode* T, JSON& j, int& index) 
{
	int i = index;
	j[i]["value"] = T->val;
	//j[i]["index"] = intToString(index);
	if (T->left != NULL) {
		j[i]["left"] = intToString(index + 1);
		_treeToJson(T->left, j, ++index);
	}
	if (T->right != NULL) {
		j[i]["right"] = intToString(index + 1);
		_treeToJson(T->right, j, ++index);
	}
}

//将这颗树转换为Json数组
JSON treeToJson(BiTreeNode* T) 
{
	JSON j;
	int index = 0;
	//以T为根节点，从0开始重新构造节点序数，生成JSON数组
	_treeToJson(T, j, index);
	return j;
}


//将json数组转换为唯一树字符串
string jsonToString(JSON arr) 
{
	string jstr = "";
	int index = 0;
	//遍历整个json数组，将所有值取出拼接成字符串
	for (auto &j : arr.ArrayRange()) {
		jstr += intToString(index) + "|";
		jstr += j["value"].ToString() + "|";
		jstr += j["left"].ToString() + "|";
		jstr += j["right"].ToString() + "|";
		index++;
	}
	//返回的字符串决定唯一棵二叉树
	return jstr;
}


//递归遍历搜索子树
void searchChildTrees(BiTreeNode* T, map<string, int> &treeCount, map<string, JSON> &treeJSON) 
{
	//将以本结点为根的树转换为一个json数组，再将这个json数组转换成唯一的字符串序列
	JSON jArr = treeToJson(T);
	string treeKey = jsonToString(jArr);

	//如果能在序列-次数映射中，不能找到以新生成的序列为key的映射
	//就生成新的序列-次数映射，序列-json映射。
	if (treeCount.count(treeKey) == 0) {
		treeCount.insert(pair<string, int>(treeKey, 1));
		treeJSON.insert(pair<string, JSON>(treeKey, jArr));
	}
	//否则就代表这个已有的序列（子树）又出现了一次
	else {
		treeCount[treeKey] += 1;
	}

	if (T->left != NULL) {
		searchChildTrees(T->left, treeCount, treeJSON);
	}
	if (T->right != NULL) {
		searchChildTrees(T->right, treeCount, treeJSON);
	}
}


//获取二叉树所有子树的Json
JSON getAllChildTreesJson(BiTreeNode* T) 
{
	//建立序列-次数映射，序列-json映射
	map<string, int> treeCount;
	map<string, JSON> treeJSON;
	searchChildTrees(T, treeCount, treeJSON);

	JSON res;
	int index = 0;
	map<string, int>::iterator iter;
	//以序列-次数-json生成要求格式的json
	for (iter = treeCount.begin(); iter != treeCount.end(); iter++, index++) {
		res[index]["count"] = iter->second;
		res[index]["subtree"] = treeJSON[iter->first];
	}
	return res;
}


//获取二叉树节点个数
int getNums(BiTreeNode* root) 
{
	if (root == NULL)
		return 0;
	return getNums(root->left) + getNums(root->right) + 1;
}


//获取二叉树叶节点个数
int getLeafNodeNums(BiTreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	int l_nums = getLeafNodeNums(root->left);
	int r_nums = getLeafNodeNums(root->right);
	return l_nums + r_nums;
}


// 求二叉树的深度
int getDepth(BiTreeNode* root) {
	if (root == NULL)
		return 0;
	return max(getDepth(root->left), getDepth(root->right)) + 1;
}


// 求二叉树第K层的节点个数
int getNLevelNums(BiTreeNode* root, int k) {
	if (root == NULL || k == 0)
		return 0;
	if (k == 1)
		return 1;
	// 二叉树第K层的节点个数 = 左子树K-1层的节点个数 + 右子树K-1层的节点个数
	return getNLevelNums(root->left, k - 1) + getNLevelNums(root->right, k - 1);
}


/*
 * 求每层有多少个节点
 * 存入一个数组之中 
 */

vector <int> A;

void num_level(BiTreeNode* root)
{
    int depth = getDepth(root);
    cout << "all level" << depth << endl;
    int num;
    for (int i=0 ;i < depth;i++)
    {
        num =  getNLevelNums( root, i+1 );
        A.push_back( num );
    }
}
/*
 * 求每一层的开始
 *
 */
int start_level(int k)
{
    int  num = 0;
    for (int i=0 ; i <k ;i++)
    {
        num += A[i];
    }
}

/*
 *
 * 本程序核心代码
 *
 */



void LLevelOrderTravel(BiTreeNode* root) 
{
	if (root == NULL)
		return;
    
    vector <BiTreeNode*> B;
    B.push_back(root);
    int  sum = 0 ,sum1 = 0 , i , j ,t;
    int depth = getDepth(root);
    int step = 0;
    int allnum = getNums(root);
    for ( i=0 ; i <allnum  ;i++)
    {
        BiTreeNode *pp = B[i];
          
            if (pp->left){
			    B.push_back(pp->left);
               // cout << pp -> val <<endl;
            }
            if (pp->right){
                
			    B.push_back(pp->right);
               // cout << pp -> val <<endl;
            
            }
    }
    for (i =0 ;i<=depth ; i=i+2)
    {
        for(j = start_level(i) ; j <=A[i] ;j++)
        {
            cout << "this val=" << B[j]->val << endl;
            sum = sum + B[j]->val;
            step++;
        }
    }
    
    for (i =0 ;i<=depth ; i=i+2)
    {
        for(j = start_level(i) ; j <=A[i] ;j++)
        {
            cout << "this val=" << B[j]->val << endl;
            sum1 = sum1 + B[j]->val;
            step++;
        }
    }

    if(sum1 > sum)
        cout << "sum = " <<sum1 << "step=" << step <<endl;
    else 
        cout << "sum = " <<sum  << "step=" << step <<endl;
        

}
int main(int argc, char** argv)
{
    if(argv[1] == NULL)
    {
        cout <<"please input filename" << endl;
        return 0;
    }
    string a= "./";
    string json_path = a+argv[1];
	
    JSON json_data = getJsonFromFile(json_path);

	BiTreeNode* BiTree = createTreeByJson(NULL, json_data, "0");
	
    num_level(BiTree);

    for(auto num : A  )
    {
       cout << "this level "<< num <<endl;
    }

    LLevelOrderTravel(BiTree);
	
    return 0;
}


