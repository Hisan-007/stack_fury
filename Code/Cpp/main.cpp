#include<iostream>
#include<string>
#include <ctime>
#include <dshow.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <fstream>
#include <set>
#include <chrono>
using namespace std::chrono;
using namespace std;

static int counter = 0;
struct node{
    string url;
    node *left;
    node *right;
};

class UrlTree{
public:
    UrlTree();
    ~UrlTree();

    void insert(string url);
    node *search(string url);
    void destroy_tree();
    void inorder_print();
    void postorder_print();
    void preorder_print_url_tree();

private:
    void destroy_tree(node *leaf);
    void insert(string url, node *leaf);
    node *search(string url, node *leaf);
    void inorder_print(node *leaf);
    void postorder_print(node *leaf);
    void preorder_print(node *leaf);

    node *root;
};

boolean isLessThan(string a, string b){
    if(a.compare(b)<0){
        return true;
    }
    else{
        return false;
    }
}
boolean isGreaterThan(string a, string b){
    if(a.compare(b)>0){
        return true;
    }
    else {
        return false;
    }
}
boolean isEqualTo(string a, string b){
    if(a.compare(b)==0){
        return true;
    }
    else{
        return false;
    }
}

UrlTree::UrlTree(){
    root = NULL;
}

UrlTree::~UrlTree(){
    destroy_tree();
}

void UrlTree::destroy_tree(node *leaf){
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void UrlTree::insert(string url, node *leaf){

    if( isLessThan(url , leaf->url)){
        if(leaf->left != NULL){
            insert(url, leaf->left);
        }else{
            leaf->left = new node;
            leaf->left->url = url;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if(isGreaterThan(url , leaf->url)){
        if(leaf->right != NULL){
            insert(url, leaf->right);
        }else{
            leaf->right = new node;
            leaf->right->url = url;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }

}

void UrlTree::insert(string str){
    if(root != NULL){
        insert(str, root);
    }else{
        root = new node;
        root->url = str;
        root->left = NULL;
        root->right = NULL;
    }
}

node *UrlTree::search(string str, node *leaf){
    if(leaf != NULL){
        if(str == leaf->url){
            return leaf;
        }
        if(str < leaf->url){
            return search(str, leaf->left);
        }else{
            return search(str, leaf->right);
        }
    }else{
        return NULL;
    }
}

node *UrlTree::search(string str){
    return search(str, root);
}

void UrlTree::destroy_tree(){
    destroy_tree(root);
}

void UrlTree::inorder_print(){
    inorder_print(root);
    cout << "\n";
}

void UrlTree::inorder_print(node *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        cout << leaf->url << ",";
        inorder_print(leaf->right);
    }
}

void UrlTree::postorder_print(){
    postorder_print(root);
    cout << "\n";
}

void UrlTree::postorder_print(node *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        inorder_print(leaf->right);
        cout << leaf->url << ",";
    }
}

void UrlTree::preorder_print_url_tree(){
    preorder_print(root);
    cout << "\n";
}

void UrlTree::preorder_print(node *leaf){
    if(leaf != NULL){
        cout << leaf->url << ",";
        preorder_print(leaf->left);
        preorder_print(leaf->right);
    }
}

class KeywordPacket{
public:
    string keyword;
    UrlTree *urlTree = new UrlTree();
    KeywordPacket* left;
    KeywordPacket* right;
    KeywordPacket(string keyword, UrlTree* url){
        this->keyword = keyword;
        this->urlTree = url;
    }
};

// ANOTHER TREE FOR FOR KEYWORD PACKET CLASS

class KeywordTree{
public:
    KeywordPacket *root;
    KeywordTree();
    ~KeywordTree();

    void insert(KeywordPacket* keywordPacket, KeywordPacket* root);
    KeywordPacket *search(string keyword, KeywordPacket* root);
    void destroy_tree(KeywordPacket* root);
    //void inorder_print();
    //void postorder_print();
    //void preorder_print_url_tree();

    //void destroy_tree(KeywordPacket *keywordPacket);
    //void insert(KeywordPacket kp, KeywordPacket *parent);
    //node *search(KeywordPacket kp, node *parent);
    void inorder_print(KeywordPacket *parent);
    void postorder_print(KeywordPacket *parent);
    void preorder_print(KeywordPacket *parent);


};

KeywordTree::KeywordTree(){
    root = NULL;
}

KeywordTree::~KeywordTree(){
    destroy_tree(root);
}

void KeywordTree::destroy_tree(KeywordPacket* root){
    if(root != NULL){
        destroy_tree(root->left);
        destroy_tree(root->right);
        delete root;
    }
}

void KeywordTree::insert(KeywordPacket *keywordPacket, KeywordPacket * parent){
    //string keyword = keywordPacket->keyword;
    if(counter>=7215){
        cout<<"keyword: "<<keywordPacket->keyword<<" parent: "<<parent->keyword<<endl;
    }
    if(parent==NULL){
        root = keywordPacket;
        root->left = NULL;
        root->right = NULL;
        cout<<"how"<<endl;
        //cout<<"kw: "<<keywordPacket->keyword<<" pkw: "<< keywordPacket->keyword <<endl;
    }
    else if( isLessThan(keywordPacket->keyword , parent->keyword)){
        if(counter>=7215) {
            cout << counter<< " left: "<<keywordPacket->keyword <<" | "<<parent->keyword<< endl;
        }
        if(parent->left != NULL){
            insert(keywordPacket, parent->left);
        }else{
            parent->left = keywordPacket;
            parent->left->keyword = keywordPacket->keyword;
            parent->left->left = NULL;
            parent->left->right = NULL;
        }
    }else if(isGreaterThan(keywordPacket->keyword , parent->keyword) && !isEqualTo(keywordPacket->keyword, parent->keyword)){
        if(counter>=7215) {
            cout << counter<< " right: "<< keywordPacket->keyword <<" | "<<parent->keyword<< endl;
        }
        if(parent->right != NULL){
            insert(keywordPacket, parent->right);
        }else{
            parent->right = keywordPacket;
            parent->right->keyword = keywordPacket->keyword;
            parent->right->right = NULL;
            parent->right->left = NULL;
        }
    }

}
// CODE FROM PREVIOUS VERSION
/*void KeywordTree::insert(string str){
    if(root != NULL){
        insert(str, root);
    }else{
        root = new node;
        root->url = str;
        root->left = NULL;
        root->right = NULL;
    }
}*/

KeywordPacket *KeywordTree::search(string keyword, KeywordPacket *root){
    if(root != NULL){
        if(keyword == root->keyword){
            return root;
        }
        if( isLessThan(keyword, root->keyword) ){
            return search(keyword, root->left);
        }else{
            return search(keyword, root->right);
        }
    }else{
        return NULL;
    }
}
// CODE FROM PREVIOUS VERSION
/*node *KeywordTree::search(string str){
    return search(str, root);
}*/

/*void KeywordTree::destroy_tree(){
    destroy_tree(root);
}*/

/*void KeywordTree::inorder_print(){
    inorder_print(root);
    cout << "\n";
}*/

void KeywordTree::inorder_print(KeywordPacket *root){
    if(root != NULL){
        inorder_print(root->left);
        cout << root->keyword << ",";
        inorder_print(root->right);
    }
    cout<<endl;
}

/*void KeywordTree::postorder_print(){
    postorder_print(root);
    cout << "\n";
}*/

void KeywordTree::postorder_print(KeywordPacket *root){
    if(root != NULL){
        inorder_print(root->left);
        inorder_print(root->right);
        cout << root->keyword << ",";
    }
}

/*void KeywordTree::preorder_print(){
    preorder_print_url_tree(root);
    cout << "\n";
}*/

void KeywordTree::preorder_print(KeywordPacket *root){
    if(root != NULL){
        cout << root->keyword << ",";
        cout<<"[\n";
        root->urlTree->preorder_print_url_tree();
        cout<<"]"<<endl;
        preorder_print(root->left);
        preorder_print(root->right);
    }

}


vector<string> split(string str, char ch){
    int s = 0;
    vector<string> v;
    for(int i = 0; i<str.length(); i++){
        if(str[i]==ch){
            if(str.substr(s, i-s)!="") {
                v.push_back(string(str.substr(s, i - s)));
            }
            s = i+1;
        }
    }
    if (str.substr(s, str.length() - s) != "") {
        v.push_back(string(str.substr(s, str.length() - s)));
    }
    return v;
}


void give_f(){
    ifstream file;
    string text;
    vector<string> data;
    vector<string> rows;
    //vector<KeywordPacket> keywordPackets;
    KeywordTree* keywordTree = new KeywordTree();
    //int counter = 0;



    file.open("E:\\University_stuff\\semester_3\\data_structures\\end_semester_project\\AnswerBase\\final_data_bank.txt");
    if(file){
        getline(file, text, '\0');
        data = split(text, '\n');
        cout<<"size: "<<data.size()<<endl;
    }
    //auto pointer_data_start = data.begin();
    for(auto pointer_data_start = data.begin(); pointer_data_start<data.end(); pointer_data_start++){
        rows = split(*pointer_data_start, ' ');
        
        UrlTree *tempUrlTree = new UrlTree();
        // starting from +1 instead of 0 because 0th index is going to be the keyword, and the other ones are links
        for(auto pointer_row_start = rows.begin()+1; pointer_row_start<rows.end(); pointer_row_start++){
            tempUrlTree->insert(*pointer_row_start);
            //cout<<"valeu: "<<*pointer_row_start<<endl;
        }
        KeywordPacket *tempKeyWordPacket = new KeywordPacket(*rows.begin(), tempUrlTree);
        cout << "counter 0: " << counter << endl;
        keywordTree->insert(tempKeyWordPacket, keywordTree->root);//beep beep start
        cout<<"counter 1: "<<counter<<endl;
        counter++;
        //KeywordPacket keywordPacket = new KeywordPacket();
    }
}

class NewKeywordPacket{
public:
    string keyword;
    vector<string> listOfUrls;
    NewKeywordPacket(string keyword, vector<string> listOfUrls){
        this->keyword = keyword;
        this->listOfUrls = listOfUrls;
    }
    void print_list_of_urls(){
        for(auto i = listOfUrls.begin(); i<listOfUrls.end(); i++){
            cout<<"url: "<<*i<<endl;
        }
    }
};

class AnswerPacket{
public:
    string url;
    int count;
    AnswerPacket(string url, int count){
        this->url = url;
        this->count = count;
    }
};
vector<NewKeywordPacket> give_linear_f(){
    ifstream file;
    string text;
    vector<string> data;
    vector<string> rows;
    vector<NewKeywordPacket> listOfKeywords;



    file.open("E:\\University_stuff\\semester_3\\data_structures\\end_semester_project\\AnswerBase\\final_data_bank.txt");
    if(file){
        getline(file, text, '\0');
        data = split(text, '\n');
        cout<<"size: "<<data.size()<<endl;
    }
    for(auto pointer_data_start = data.begin(); pointer_data_start<data.end(); pointer_data_start++){
        rows = split(*pointer_data_start, ' ');
        string temp_keyword = *rows.begin();
        rows.erase(rows.begin());
        NewKeywordPacket keywordPacket = NewKeywordPacket(temp_keyword, rows);
        listOfKeywords.push_back(keywordPacket);
    }
    return listOfKeywords;
}

vector<string> giveKeywords(string question, vector<string>* stop_words){
    vector<string> list_of_keywords = split(question, ' ');
    set<string> set_of_keywords(list_of_keywords.begin(), list_of_keywords.end());
    vector<string> answer(set_of_keywords.begin(), set_of_keywords.end());
    vector<string> final_answer;
    for(auto i = set_of_keywords.begin(); i!=set_of_keywords.end(); i++){
        if( !(find(stop_words->begin(), stop_words->end(), *i)!=stop_words->end())){
            // not in stop keywords;
            final_answer.push_back(*i);
        }
    }
    return answer;
}

vector<string> give_websites_for_keyword(string keyword, vector<NewKeywordPacket> *listOfKeywords){
    for(auto i = listOfKeywords->begin(); i<listOfKeywords->end(); i++){
        if((*i).keyword==keyword){
            // they are equal
            vector<string> answer = (*i).listOfUrls;
            return answer;
        }
    }
    vector<string> empty;
    return empty;
}

vector<string> give_all_websites_for_given_keyword_list(vector<string> list_of_keywords, vector<NewKeywordPacket> *allKeywords){
    vector<string> websites; // w as per my python program
    for(auto i = list_of_keywords.begin(); i<list_of_keywords.end(); i++){
        vector<string> sub_websites = give_websites_for_keyword(*i, allKeywords);
        if(sub_websites.size()>0) {
            // alternative to try except of my python program
            for (auto j = sub_websites.begin(); j < sub_websites.end(); j++) {
                websites.push_back(*j);
            }
        }
    }
    return websites;
}

int count_the_websites_with_url(string url, vector<string> list_of_websites){
    int count = 0;
    for(auto i = list_of_websites.begin(); i<list_of_websites.end(); i++){
        if((*i).compare(url)==0){
            count++;
        }
    }
    return count;
}

vector<AnswerPacket> perform_crux(vector<string> websites){
    set<string> set_of_websites(websites.begin(), websites.end());
    vector<string> w(set_of_websites.begin(), set_of_websites.end());
    vector<AnswerPacket> listOfAnswerPackets;
    for(auto i = w.begin(); i<w.end(); i++){

        AnswerPacket *answerPacket = new AnswerPacket(*i, count_the_websites_with_url(*i, websites));
        listOfAnswerPackets.push_back(*answerPacket);
    }
    return listOfAnswerPackets;
}

int give_maximum_count(vector<AnswerPacket> c){
    int max = 0;
    for(auto i = c.begin(); i<c.end(); i++){
        if( (*i).count>max){
            max = (*i).count;
        }
    }
    return max;
}
void search(vector<AnswerPacket> c){
    int max = give_maximum_count(c);
    for(auto i = c.begin(); i<c.end(); i++){
        if( (*i).count == max-1 || (*i).count==max){
            cout<<"LINK: "<< (*i).url<<endl;
        }
    }
    cout<<"MAX: "<<max<<endl;
}
vector<string> give_stop_words(){
    ifstream file;
    string text;
    vector<string> stop_words;
    file.open("E:\\University_stuff\\semester_3\\data_structures\\end_semester_project\\AnswerBase\\stop_words.txt");
    if(file){
        getline(file, text, '\0');
        stop_words = split(text, '\n');
    }
    return stop_words;
}

void google(string text, vector<NewKeywordPacket> *allKeywords, vector<string> *stop_words){
    vector<string> question_keywords = giveKeywords(text, stop_words);
    vector<string> all_websites = give_all_websites_for_given_keyword_list(question_keywords, allKeywords);
    vector<AnswerPacket> c = perform_crux(all_websites);
    search(c);
}
int main(){
    vector<NewKeywordPacket> allKeywords = give_linear_f();
    vector<string> stop_words = give_stop_words();
    cout<<"starting now: "<<endl;
    auto start = high_resolution_clock::now();
    google("how do i find the time complexity of hash map", &allKeywords, &stop_words);
    auto stop = high_resolution_clock::now();
    cout<<"TIME: "<< duration_cast<microseconds>(stop-start).count()/1000000<<endl;
    return 0;
}



