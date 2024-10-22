#ifndef _SORT_H_
#define _SORT_H_

#include <cmath>
#include <stdexcept>

namespace my_algorithm{
	
////////////////////////////////////////////////////////////////////////////////
/// @brief Swap values of two elements
/// @tparam T Value type
/// @param a First value
/// @param b Second value
template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Bubble Sort - Example
template<class RandomAccessIterator, class Compare>
  void bubble_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    // Traverse from left to right for each ith largest element positioning
    for(RandomAccessIterator i = first; i != last; ++i)
	  // Compare each element with its right neighbor to bubble up ith largest element
      for(RandomAccessIterator j = first; j+1 != last; ++j)
        if(comp(*(j+1), *j)) // Compare j with its right neighbor 
          swap(*(j+1), *j);  // Swap if neighbor is smaller
  }
	
////////////////////////////////////////////////////////////////////
/// @brief Your implementation of insertion selection sort
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.	
template<typename RandomAccessIterator, typename Comparator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Comparator comp){
	/// @TODO

  //declare RandomAccessIterator i and j to be used in insertion_sort()
  RandomAccessIterator j, i;

  //assuming 1st element of the array is sorted by itself, we therefore start with the 2nd 
  //element as our key value (ie "first+1") and compare it with previous element(s) in array to 
  //determine proper positioning
for (i = first +1; i != last; ++i) {
    
    //make "key" value equal to the value of i at its given iteration of the "for" loop
    //...ie first key value will be 2nd element in vector and so on...
         typename std::iterator_traits<RandomAccessIterator>::value_type key = *i;

        //we shall set iterator j to be equal to the element prior to vec[i]
        //separing the vec into sorted and unsorted portions...j will point to sorted portion
         j = i - 1;

        //essentially, if the right-most sorted element is atleast the first element of the vect
        // and the element of vec[j] is greater than key, then...
        while (j >= first && comp(key, *j)) {
            *(j + 1) = *j; //...then, set vec[j] equal to vec[j+1]
            j= j-1; //move val of j down a position 
        }
        *(j + 1) = key; //pass key val to vec[j+1]...the elment index that we removed earlier,
        //we replace that missing element val with key val
    }
}

////////////////////////////////////////////////////////////////////
/// @brief Your implementation of merging two sorted sequences  
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of the first sequence to be merged
/// @param mid Initial position of the second sequence to be merged
/// @param last Final position of the second sequence to be merged
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.

template<typename RandomAccessIterator, typename Comparator>
void merge(RandomAccessIterator first, RandomAccessIterator mid, RandomAccessIterator last, Comparator comp){
  /// Hint: To allocate external memory to store merging of result use
  /// std::vector<typename RandomAccessIterator::value_type> 
  /// Remember to copy back the merged result
  /// @TODO

//this is the vector to be passed the elemenets once first half and second half 
   //of sequence is sorted.
    std::vector<typename RandomAccessIterator::value_type> ext_mem;

    //represents the iterators pertaining to either halves of the sequence
    //with i being first position up till before mid and j being at mid till < final position
    RandomAccessIterator i = first;
    RandomAccessIterator j = mid;

  //merging..so long: 
    while (i < mid && j < last) { //iterator for first half is < mid and iterator for 2nd half is < final position
        //we shall use our comparator to determine which element from either sequence 
        //shall be merged into our ext_mem vect. We put ith element into new vect if its less than
        //the jth element... if not true, then we put the jth element into the new vect. 
        //Each time an element is added from either we increment the iterator corrosponding to the sequence the element came from.
        if (comp(*i, *j)) { 
            ext_mem.push_back(*i);
            i++;
        } else {
            ext_mem.push_back(*j);
            j++;
        }
    }

//Important, say if 2nd half  sequence iterator reached the end of 
//its sequence before the first half one did
//.. then, clearly there are elements remainging in 1st half
//and we know those elements to be sorted... so we simply add those elements in order
    while (i < mid) {
        ext_mem.push_back(*i);
        i++;
    }

    //Important, say if 1st half  sequence iterator reached the end of 
  //its sequence before the second half one did
  //.. then, clearly there are elements remainging in 2nd half
  //and we know those elements to be sorted... so we simply add those elements in order
    while (j < last) {
        ext_mem.push_back(*j);
        j++;
    }

//we know first to be initial position of sequence/vect, we can use copy() function 
//to copy elements from our newfound ext_mem vect which now contains the sorted vector
//we can copy that to the initial vector that was passed to us via the test suites 
//thus, making the vector passed in the beginning... the newly sorted vector.
    std::copy(ext_mem.begin(), ext_mem.end(), first);

}

////////////////////////////////////////////////////////////////////
/// @brief Your implementation of merging n/k sorted sequences of size k 
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param k Maximum size of each sorted sequence
/// @param first Initial position of first sequence to be merged
/// @param last Final position of last sequence to be merged
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
template<typename RandomAccessIterator, typename Comparator>
void merge_k(long int k, RandomAccessIterator first, RandomAccessIterator last, Comparator comp){
  /// @TODO

  //n/k subsequences... traditional merge is 2.... essentially, similair to exercise from slide 2 ppt...
//not entirely sure how to implement this in code


//vector to be passed sorted elements once k sequences are sorted...
    std::vector<typename RandomAccessIterator::value_type> ext_mem2;


//make iterators that go with first half of sequence and 2nd half
  RandomAccessIterator k1 = first;
  RandomAccessIterator k2 = last;
    while (k1 < first && k2 < last) { 
        if (comp(*k1, *k2))
          { 
            ext_mem2.push_back(*k1);
            k1++;
          } else 
          {
            ext_mem2.push_back(*k2);
            k2++;
          }
    }

    //not entirely sure how to finish implementation of merge_k from here unfortunately.
}

////////////////////////////////////////////////////////////////////
/// @brief Your implementation of merge sort
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param k  Each sub-sequence maximum size at lowest level
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.	
template<typename RandomAccessIterator, typename Comparator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last, Comparator comp, long int k = 1){
	/// @TODO

   //if size of sequence is <= k...use insertion sort to sort sequence
     if (std::distance(first, last) <= k) {
        insertion_sort(first, last, comp);
     }

     //else, perform merge operation
     else
     {
       RandomAccessIterator mid = first + (last - first) / 2; 
       merge_sort(first, mid, comp, k);
       merge_sort(mid, last, comp, k);
        merge(first, mid, last, comp);
     }
}

}

#endif