/*
AUTHORS: AMNA KHALID & YASH PANDEY
DATE:04/10/19
Funtionality: Included with these documents is the code of selction sort, quick sort,
              merge Sort and insertion sort.
              These algorithmns are used to sort vectors of size 1000 to 25,000
              (in incremens of 1000). The respective time taken for each vector
              was recorded and tehn used to plot graphs to show time complexity.
*/

#include <sys/time.h>
#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> & vec);
int partition(vector<int> & vec, int start, int finish);
void quicksort(vector<int> & vec, int start, int finish);
void q_sort(vector<int> & vec);
void m_merge(vector<int>& vec, vector<int>& v1, vector<int>& v2);
void m_sort(vector<int> & vec);
void ins_sort(vector<int> & vec);
int main() {
  /*
  Below is our code used to calculate the time taken for each
  algorithmn to sort its vector
  */
   timeval timeBefore, timeAfter;
   long diffSeconds, diffUSeconds;

   // Code used to generate new vectors and calculate the time taken to sort
   for(int j =1; j <= 100 ; j++){
        vector <int> input_list;
     for(int i = 1; i <= j * 1000; i++){
       int input_num = rand() % 100;
       input_list.push_back(input_num);
     }


// timeval type defined in sys/time.h
// elapsed seconds and microseconds
      gettimeofday(&timeBefore, NULL);  // get the time before
//      ins_sort(input_list);
      gettimeofday(&timeAfter, NULL);   // get the time after
      diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;    // elapsed seconds
      diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
      double time = diffSeconds + diffUSeconds / 1000000.0;  // total elapsed time
      //cout<<time<<endl;
    }
/*
 In order to show that all the sorting algorithmns work we display a list of sorted
  to the terminal
 along.
*/
   vector <int> input_list; // declaring a vector that can be used in this scope.
   //Output for selection sort=================================================
   for(int i = 1; i <= 5; i++){
     int input_num = rand() % 100;
     input_list.push_back(input_num);
   }
   cout<<"\n"<<"Unsorted List:"<<"\n";
   for(auto item : input_list){
     cout<<item<<"\t";
   }
   cout<<"\n"<<"Selction Sort:"<<"\n";
   selectionSort(input_list);
   for(auto item : input_list){
     cout<<item<<"\t";
   }
   input_list.clear();

   //Output for Insertion Sort======================================================
   for(int i = 1; i <= 5; i++){
     int input_num = rand() % 100;
     input_list.push_back(input_num);
   }
   cout<<"\n"<<"Unsorted List:"<<"\n";
   for(auto item : input_list){
     cout<<item<<"\t";
   }
   cout<<"\n"<<"Insertion Sort:"<<"\n";
   ins_sort(input_list);
   for(auto item : input_list){
     cout<<item<<"\t";
   }
   input_list.clear();


   //Output for merge sort=====================================================
   for(int i = 1; i <= 5; i++){
     int input_num = rand() % 100;
     input_list.push_back(input_num);
   }
   cout<<"\n"<<"Unsorted List:"<<"\n";
   for(auto item : input_list){
     cout<<item<<"\t";
   }
   cout<<"\n"<<"Merge Sort:"<<"\n";
   m_sort(input_list);
   for(auto item : input_list){
     cout<<item<<"\t";
   }
   input_list.clear();

   //Output for quick sort=====================================================
   for(int i = 1; i <= 5; i++){
     int input_num = rand() % 100;
     input_list.push_back(input_num);
   }
   cout<<"\n"<<"Unsorted List:"<<"\n";
   for(auto item : input_list){
     cout<<item<<"\t";
   }
   cout<<"\n"<<"Quick Sort:"<<"\n";
   q_sort(input_list);
   for(auto item : input_list){
     cout<<item<<"\t";
   }
   input_list.clear();

   cout<<"\n";

return 0;
}

// Code for Selction Sort======================================================
void selectionSort(vector<int> & vec) {
    int n = vec.size();
    for (int lh = 0; lh < n; lh++) {
      int rh = lh;
        for (int i = lh + 1; i < n; i++) {
          if (vec[i] < vec[rh]) rh = i; }
          int temp = vec[lh];
          vec[lh] = vec[rh];
          vec[rh] = temp;
    }
  }

//Code for Insertion Sort======================================================
void ins_sort(vector<int> & vec){
    int i, key;
    for (int j = 1; j<vec.size(); j++){
      key = vec[j];
      i = j-1;
      while (i>=0 && (vec[i]> key)){
        vec[i+1] = vec[i];
        i -= 1;
      }
      vec[i+1] = key;
    }
  }


// Code for quick sort=========================================================
  void q_sort(vector<int> & vec) {
     quicksort(vec, 0, vec.size() - 1);
  }

  void quicksort(vector<int> & vec, int start, int finish) {
     if (start >= finish) return;
     int boundary = partition(vec, start, finish);
     quicksort(vec, start, boundary - 1);
     quicksort(vec, boundary + 1, finish);
  }

  int partition(vector<int> & vec, int start, int finish) {
       int pivot = vec[start];
       int lh = start + 1;
       int rh = finish;
       while (true) {
          while (lh < rh && vec[rh] >= pivot) rh--;
          while (lh < rh && vec[lh] < pivot) lh++;
          if (lh == rh) break;
          int tmp = vec[lh];
          vec[lh] = vec[rh];
          vec[rh] = tmp;
       }
       if (vec[lh] >= pivot) return start;
       vec[start] = vec[lh];
       vec[lh] = pivot;
       return lh;
  }
// Code used for Merge sort====================================================
void m_merge(vector<int>& vec, vector<int>& v1, vector<int>& v2){
    int n1 = v1.size();
    int n2 = v2.size();
    int p1 = 0;
    int p2 = 0;
    while(p1<n1 && p2 <n2){
      if(v1[p1]<v2[p2]){
        vec.push_back(v1[p1++]);
      }
      else{
        vec.push_back(v2[p2++]);
      }
    }
    while(p1<n1) vec.push_back(v1[p1++]);
    while(p2<n2) vec.push_back(v2[p2++]);
  }

  void m_sort(vector<int> & vec) {
     int n = vec.size();
     if (n <= 1) return;
     vector<int> v1;
     vector<int> v2;
  for (int i = 0; i < n; i++) { if (i < n / 2) {
  v1.push_back(vec[i]); } else {
           v2.push_back(vec[i]);
        }
     }
     m_sort(v1);
     m_sort(v2);
     vec.clear();
     m_merge(vec,v1,v2);
  }

/*
Time for Selction Sort=========================================================
0.004262
0.007769
0.017321
0.02853
0.04464
0.063893
0.086246
0.112579
0.140157
0.176302
0.211892
0.252009
0.295524
0.338801
0.391269
0.444392
0.503078
0.561623
0.636328
0.698728
0.765608
0.84771
0.926043
0.998386
1.08608
1.17341
1.2658
1.36893
1.47207
1.56751
1.66516
1.78833
1.89623
2.00914
2.13575
2.26179
2.48773
2.52936
2.71488
2.83962
2.9394
3.05672
3.23075
3.40412
3.55135
3.7587
3.90406
4.02414
4.19231
4.37633
4.53529
4.7114
4.97777
5.1413
5.34023
5.53581
5.72824
5.94202
6.15328
6.34741
6.56516
6.77006
7.08482
7.25558
7.46698
7.66942
7.94263
8.19949
8.40811
8.64941
8.92042
9.14518
9.4121
9.70188
9.9049
10.1813
10.4867
10.7287
11.0305
11.3334
11.5294
11.818
12.1298
12.4215
12.6935
13.028
13.4779
13.8343
13.9315
14.2384
14.6476
14.9109
15.2328
15.5685
15.8299
16.1879
16.4914
17.1262
17.5473
17.5577

Time for insertion Sort========================================================
0.002622
0.005201
0.011049
0.019687
0.03099
0.043773
0.059002
0.075206
0.096336
0.119143
0.14288
0.171653
0.199945
0.23333
0.267285
0.305858
0.337558
0.377846
0.423722
0.474323
0.519416
0.56924
0.615887
0.674899
0.722916
0.784792
0.844974
0.91206
0.973183
1.05604
1.11672
1.1967
1.2663
1.34133
1.42367
1.51925
1.60095
1.67991
1.76794
1.85296
1.96922
2.04608
2.16375
2.25112
2.35265
2.45816
2.58332
2.67532
2.79909
2.91837
3.03423
3.16475
3.27819
3.39767
3.5428
3.65579
3.7691
3.91237
4.07561
4.19328
4.34972
4.47206
4.61248
4.80063
4.92742
5.0712
5.22357
5.41722
5.53537
5.73435
5.85656
6.0474
6.26608
6.39213
6.52731
6.71278
6.97301
7.09455
7.27368
7.49029
7.6532
7.88128
8.00654
8.2743
8.40412
8.66813
8.82023
9.03431
9.22982
9.47508
9.61407
9.8994
10.1908
10.4545
10.7136
10.8424
11.0848
11.2884
11.7214
11.651

Time for Quick Sort============================================================
0.000413
0.001006
0.001128
0.000508
0.000606
0.000793
0.000981
0.001592
0.001466
0.001735
0.001997
0.002543
0.002668
0.002945
0.003527
0.003763
0.004333
0.00449
0.0049
0.005863
0.006375
0.00636
0.006804
0.007347
0.008454
0.008502
0.008997
0.009573
0.01086
0.011166
0.011919
0.012447
0.013128
0.014119
0.014683
0.015768
0.016278
0.017123
0.018221
0.018755
0.019727
0.020769
0.021295
0.022535
0.023331
0.024196
0.025078
0.026267
0.027344
0.028341
0.029305
0.030587
0.031541
0.032787
0.033743
0.03502
0.036011
0.03734
0.038327
0.03948
0.040823
0.041514
0.043092
0.044453
0.045669
0.047133
0.048191
0.049407
0.050757
0.051903
0.05292
0.055328
0.057041
0.058522
0.059719
0.061561
0.063071
0.064511
0.066008
0.067023
0.06906
0.070835
0.072384
0.074105
0.075861
0.077935
0.078714
0.080172
0.082319
0.083858
0.086162
0.087827
0.090246
0.108072
0.094305
0.095418
0.095872
0.098008
0.100815
0.102616

Time for merge sorted==========================================================
0.003169
0.001905
0.003254
0.003764
0.005513
0.006266
0.006926
0.008095
0.009065
0.011423
0.011251
0.012258
0.013651
0.014434
0.015549
0.016233
0.018009
0.019365
0.0204
0.022076
0.023171
0.023802
0.02478
0.025999
0.027181
0.027783
0.02871
0.029703
0.030656
0.031533
0.032132
0.033147
0.03448
0.036298
0.037484
0.039373
0.040479
0.041308
0.043626
0.043576
0.045061
0.045909
0.047614
0.048241
0.049459
0.050266
0.051335
0.052916
0.054553
0.054168
0.055761
0.056517
0.057391
0.058593
0.059245
0.060279
0.06142
0.06186
0.062938
0.064145
0.065085
0.065627
0.067448
0.067847
0.068423
0.071222
0.072409
0.074084
0.075261
0.076557
0.078334
0.07969
0.080669
0.082647
0.083835
0.084802
0.085872
0.08669
0.088045
0.089572
0.090678
0.091351
0.09251
0.093758
0.09497
0.095797
0.097388
0.098443
0.099494
0.100467
0.101483
0.102174
0.103698
0.10447
0.105382
0.105134
0.10618
0.107304
0.109438
0.10905
*/
