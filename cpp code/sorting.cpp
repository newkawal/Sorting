#include <bits/stdc++.h>
using namespace std;
void merging(int one[],int os,int two[],int ts,int merged[]){
    int i=0,j=0,k=0;
    while(i<=os && j<=ts){
        if(one[i] < two[j]){
            merged[k]=one[i];
            i++;
            k++;
        }
        else{
            merged[k]=two[j];
            j++;
            k++;
        }
    }
    while(i<os){
        merged[k]=one[i];
            i++;
            k++;
    }
    while(j<ts){
        merged[k]=two[j];
            j++;
            k++;
    }
}
int merge(int arr[],int s,int mid,int e){
    int c=0;
    int i=s,j=mid+1,k=0;
    int narr[e-s+1];
    while(i<=mid && j<=e){
        if(arr[i] < arr[j]){
            narr[k]=arr[i];
            i++;
            k++;
        }
        else{
            c=mid-i+1;
            narr[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        narr[k]=arr[i];
            i++;
            k++;
    }
    while(j<=e){
        narr[k]=arr[j];
            j++;
            k++;
    }
    for(int i=0;i<k;i++){
        arr[i+s]=narr[i];
    }
    return c;
}
int merged(int arr[],int lo,int hi){
    if(lo==hi){
        return 0;
    }
    int mid=(lo+hi)/2;
    int i1=merged(arr,lo,mid);
    int i2=merged(arr,mid+1,hi);
    int i3=merge(arr,lo,mid,hi);
    return i1+i2+i3;
}

int partioning(int arr[],int pivot,int n){
    int p=0,i=0;
    while(i<n){
        if(arr[i]<pivot){
            swap(arr[i],arr[p]);
            i++;
            p++;
        }
        else {
            i++;
        }
    }
    return p-1;
}
void moveztoend(int arr[],int n){
    int z=n-1,nz=n-1;
    while(z>=0){
        if(arr[z]==0){
            z--;
        }
        else {
           swap(arr[z],arr[nz]);
            z--;
            nz--;
        }
    }
}
void sort012(int arr[],int n){
    int o=0,t=0,z=0;
    while(t<n){
        if(arr[t]==2){
            t++;
        }
        else if(arr[t]==1){
            swap(arr[o],arr[t]);
            t++;o++;
        }
        else if(arr[t]==0){
            swap(arr[o],arr[t]);
            t++;
            swap(arr[o],arr[z]);
            o++;z++;
        }
    }
}
int part(int arr[],int lo,int hi){
    int p=lo,i=lo;
    int pivot=arr[hi];
    while(i<=hi){
        if(arr[i]<=pivot){
            swap(arr[i],arr[p]);
            i++;
            p++;
        }
        else {
            i++;
        }
    }
    return p-1;
}
void quick_sort(int arr[],int lo,int hi){
    if(lo>=hi){
        return;
    }
    int pi=part(arr,lo,hi);
    quick_sort(arr,lo,pi-1);
    quick_sort(arr,pi+1,hi);
}
int quick_sselect_ksmallest(int arr[],int k,int lo,int hi){
    if(lo>=hi){
        return -1;
    }
    int pi=part(arr,lo,hi);
    if(pi==k){
        return arr[pi];
    }
    else if(k>pi){
        return quick_sselect_ksmallest(arr,k,pi+1,hi);
    }
    else if(k<pi){
        return quick_sselect_ksmallest(arr,k,lo,pi-1);
    }
}
int main() {
    // int one[]={10,20,30,40,50};
    // int two[]={11,15,19,22,28,65,67};
    // int merged[14];
    // merging(one,5,two,7,merged);
    // for(int i=0;i<13;i++){
    //     cout<<merged[i]<<" ";
    // }
    // int arr[]={2,7,5,4,6,8,9,1};
    // int c=merged(arr,0,7);
    // for(int i=0;i<8;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<c;
    // int arr[]={2,9,0,0,5,0,8,0,6,1};
    // int arr1[]={12,9,3,11,8,1,7,4};
    // int arr2[]={0,1,1,2,0,2,1,0,1,0,2,0,2};
    // // moveztoend(arr,10);
    // cout<<partioning(arr1,8,8)<<endl;
    // // sort012(arr2,13);
    // for(int i=0;i<8;i++){
    //     cout<<arr1[i]<<" ";
    // }
    int arr[]={2,7,5,4,6,8,9,1};
    quick_sort(arr,0,7);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<quick_sselect_ksmallest(arr,4,0,7);
    return 0;
}
