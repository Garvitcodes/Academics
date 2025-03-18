#include<stdio.h>
#include<stdlib.h>
typedef struct node* NODE;
struct node{
    int ele;
    NODE next;
};
typedef struct list* LIST;
struct list{
    int count;
    NODE head;
};
LIST createlist(){
    LIST mylist;
    mylist=(LIST) malloc(sizeof(*mylist));
    mylist->count=0;
    mylist->head=NULL;
    return mylist;
}
NODE createnode(int value){
    NODE mynode;
    mynode=(NODE) malloc(sizeof(*mynode));
    mynode->ele=value;
    mynode->next=NULL;
    return mynode;
}
void insertbeg(NODE n1,LIST l1){
    if(l1->count==0){
        l1->head=n1;
        n1->next=NULL;
        l1->count++;
    }
    else{
        n1->next=l1->head;
        l1->head=n1;
        l1->count++;
    }
}
void insertend(NODE n1,LIST l1){
     if(l1->count==0){
        l1->head=n1;
        n1->next=NULL;
        l1->count++;
    }
    else{
        NODE temp=l1->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n1;
        n1->next=NULL;
        l1->count++;
    }
}
void insertafterele(NODE n1,LIST l1,int n){
     if(l1->count==0){
        l1->head=n1;
        n1->next=NULL;
        l1->count++;
    }
    else{
       NODE temp=l1->head;
       NODE prev=temp;
       while(temp!=NULL){
            if(temp->ele==n){
                break;
            }
            prev=temp;
            temp=temp->next;
       }
       if(temp==NULL){
        printf("Elemement not in list\n");
       }
       else if(temp->next==NULL){
        temp->next=n1;
        n1->next=NULL;
        l1->count++;
       }
       else{
        prev=temp;
        temp=temp->next;
        prev->next=n1;
        n1->next=temp;
        l1->count++;
       }

    }
}
void insertbeforeele(NODE n1,LIST l1,int n){
     if(l1->count==0){
        l1->head=n1;
        n1->next=NULL;
        l1->count++;
    }
    else if(l1->count==1){
            NODE temp=l1->head;
            if(temp->ele==n){
                l1->head=n1;
                n1->next=temp;
                l1->count++;
            }
            else{
                printf("Element not in list");
            }
    }
    else{
       NODE temp=l1->head;
       NODE prev=temp;
       while(temp!=NULL){
            if(temp->ele==n){
                break;
            }
            prev=temp;
            temp=temp->next;
       }
       if(temp==NULL){
        printf("Elemement not in list\n");
       }
       else if(temp->next==NULL){
        prev->next=n1;
        n1->next=temp;
        l1->count++;
       }
       else if(temp==l1->head){
            l1->head=n1;
            n1->next=temp;
            l1->count++;
       }
       else{
        prev->next=n1;
        n1->next=temp;
        l1->count++;
       }

    }
}
void removebeg(LIST l1){
    if(l1->count==0){
        printf("LIST is empty\n");
    }
    else if(l1->count==1){
        free(l1->head);
        l1->head=NULL;
        l1->count--;
    }
    else{
        NODE temp=l1->head;
        l1->head=temp->next;
        free(temp);
        l1->count--;
    }
}
void removeend(LIST l1){
    if(l1->count==0){
        printf("LIST is empty\n");
    }
    else if(l1->count==1){
        free(l1->head);
        l1->head=NULL;
        l1->count--;
    }
    else{
        NODE temp=l1->head;
        NODE prev=temp;
        while(temp->next!=NULL){
            prev=temp;
            temp->next=temp;
        }
        prev->next=NULL;
        free(temp);
        l1->count--;
    }
}
void removelenode(LIST l1,int n){
     if(l1->count==0){
        printf("LIST is empty\n");
    }
    else if(l1->count==1){
        NODE temp=l1->head;
        if(temp->ele==n){
            l1->head=NULL;
            free(temp);
            l1->count--;
        }
        else{
            printf("Element is not in list\n");
        }
    }
    else{
        NODE temp=l1->head;
        NODE prev=temp;
        while(temp!=NULL){
            if(temp->ele==n){
                break;
            }
            prev=temp;
            temp=temp->next;
       }
       if(temp==NULL){
        printf("Elemement not in list\n");
       }
       else if(temp->next==NULL){
        prev->next=NULL;
        free(temp);
        l1->count--;
       }
       else if(temp==l1->head){
        l1->head=temp->next;
        free(temp);
        l1->count--;
       }
       else{
        prev->next=temp->next;
        free(temp);
        l1->count--;
       }
    }
}
void displaylist(LIST l1){
    NODE temp=l1->head;
    int i=0;
    while(temp!=NULL){
        printf("Element is %d at index %d\n",temp->ele,i);
       temp=temp->next;
       i++;
    }
}
void reverselist(LIST l1){
    NODE current=l1->head;
    NODE after=NULL;
    NODE prev=NULL;
    while(current!=NULL){
        after=current->next;
        current->next=prev;
        prev=current;
        current=after;
    }
    l1->head=prev;
}
void isempty(LIST l1){
    if(l1->count==0){
        printf("Yes");
    }
    else{
        printf("No");
    }
}
void search(LIST l1,int n){
    if(l1->count==0){
        printf("List is empty\n");
    }
    else if(l1->count==1){
        NODE temp=l1->head;
        if(temp->ele==n) printf("Element is present at 0 th index\n");
        else printf("Not present\n");
    }
    else{
        int i=0;
        NODE temp=l1->head;
        while(temp!=NULL){
            if(temp->ele==n){
                break;
            }
            i++;
            temp=temp->next;
        }
        if(temp==NULL) printf("Element not present\n");
       else printf("Element is at %d index\n",i);
    }
}
void sort(LIST l1){
    if(l1->count==0){
        printf("List is empty\n");
    }
    else{
        for(int i=0;i<l1->count-1;i++){
    NODE temp=l1->head;
    NODE prev=l1->head;
         for(int j=0;j<l1->count-1-i;j++){
            NODE temp2=temp->next;
            if((temp->ele)>(temp2->ele)){
                 if(temp==l1->head){
                     l1->head=temp2;
                     temp->next=temp2->next;
                     temp2->next=temp;
                    }
                else{
                    prev->next=temp2;
                    temp->next=temp2->next;
                    temp2->next=temp;
                }
                 
                 prev=temp2;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
         }
        }
    }
}
int main(){
    LIST list;
    list=createlist();
    NODE node1,node2,node3,node4,node5,node6;
    node1=createnode(10);
    node2=createnode(20);
    node3=createnode(30);
    node4=createnode(40);
    node5=createnode(50);
    node6=createnode(60);
    insertbeg(node3,list);
    insertbeg(node4,list);
    insertbeg(node6,list);
    insertend(node1,list);
    insertafterele(node5,list,10);
    insertbeforeele(node2,list,60);
    search(list,10);
    removelenode(list,10);
    displaylist(list);
    sort(list);
    displaylist(list);
    return 0;
}
