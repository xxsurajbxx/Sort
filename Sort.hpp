#pragma once
#include <iostream>
namespace xxsurajbxx::algorithms {    template<typename T>
    void quickSort(T* arr, int lengthofArray) {
        if(lengthofArray==0) {return;}
        int pivotIndex=lengthofArray/2, pivotValue=arr[pivotIndex], LA[lengthofArray], RA[lengthofArray], Lcounter=0, Rcounter=0, pivotCount=0, cntr=0;
        for(int i=0; i<lengthofArray; i++) {
            if(arr[i]<pivotValue) {LA[Lcounter++]=arr[i];}
            if(arr[i]>pivotValue) {RA[Rcounter++]=arr[i];}
            if(arr[i]==pivotValue) {pivotCount++;}
        }
        quickSort(&LA[0], Lcounter);
        quickSort(&RA[0], Rcounter);
        for(int i=0; i<Lcounter; i++) {
            arr[cntr++] = LA[i];
        }
        for(int i=0; i<pivotCount; i++) {
            arr[cntr++] = pivotValue;
        }
        for(int i=0; i<Rcounter; i++) {
            arr[cntr++] = RA[i];
        }
    }
    template<typename T>
    void countingSort(T* arr, int lengthofArray, T lowestVal, T highestVal) {
        int range = highestVal-lowestVal;
        int occurances[range+1] = {0};
        int counter=0;
        for(int i=0; i<lengthofArray; i++) {
            if(occurances[range-(highestVal-arr[i])]==0) {
                counter=0;
                for(int x=0; x<lengthofArray; x++) {
                    if(arr[i]==arr[x]) {counter++;}
                }
                occurances[range-(highestVal-arr[i])] = counter;
                counter=0;
            }
        }
        for(int i=1; i<range+1; i++) {
            occurances[i]+=occurances[i-1];
        }
        for(int i=range; i>0; i--) {
            occurances[i] = occurances[i-1];
        }
        occurances[0] = 0;
        int index;
        for(int i=0; i<range+1; i++) {
            index = occurances[i];
            if(i<range) {
                while(index<occurances[i+1]) {
                    arr[index] = lowestVal+i;
                    index++;
                }
            }
            else {
                while(index<range+1) {
                    arr[index] = lowestVal+i;
                    index++;
                }
            }
        }
    }
    template<typename T>
    void mergeSort(T* arr, int lengthofArray) {
        if(lengthofArray==1) {return;}
        const short int M = (int)(lengthofArray/2);
        int L1[M], L2[lengthofArray-M];
        for(int i=0; i<M; i++) {
            L1[i] = arr[i];
        }
        for(int i=M; i<lengthofArray; i++) {
            L2[i-M] = arr[i];
        }
        mergeSort(&L1[0], M);
        mergeSort(&L2[0], lengthofArray-M);
        for(int x=0, y=0, counter=0; counter<lengthofArray;) {
            if(L1[x]<=L2[y]||y==lengthofArray-M) {
                arr[counter++] = L1[x++];
            }
            if(L1[x]>L2[y]||x==M) {
                arr[counter++] = L2[y++];
            }
        }
    }
    template<typename T>
    void bubbleSort(T* arr, int lengthofArray) {
        for(int q=lengthofArray-1; q>0; q--) {
            for(int i=0; i<q; i++) {
                if(arr[i]>arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                }
            }
        }
    }
    template<typename T>
    void insertionSort(T* arr, int lengthofArray) {
        for(int q=0; q<lengthofArray-1; q++) {
            if(arr[q]>arr[q+1]) {
                swap(arr[q], arr[q+1]);
                for(int i=q-1; i>=0; i--) {
                    if(arr[i]>arr[i+1]) {
                        swap(arr[i], arr[i+1]);
                    }
                    else {break;}
                }
            }
        }
    }
    template<typename T>
    void selectionSort(T* arr, int lengthofArray) {
        for(int q=0; q<lengthofArray-1; q++) {
            T lowestVal=arr[q];
            int indxofLowestVal;
            for(int i=q; i<lengthofArray; i++) {
                if(arr[i]<lowestVal) {
                    lowestVal=arr[i];
                    indxofLowestVal=i;
                }
            }
            swap(arr[q], arr[indxofLowestVal]);
        }
    }}