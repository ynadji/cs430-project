package sorts;

import java.io.*;
import java.util.LinkedList;

public class Sorts {
		  
		public int[] radix(int[] arr)
		{		  
		  
		  if (arr.length == 0 || arr.length == 1)
		    return arr;
		  
		  int maxSize = 0;
		  
		  String[] newArr = new String[arr.length];
		  
		  for(int i = 0; i < arr.length; i++)
		  {
		    String c = Integer.toString(arr[i]);
		    if (c.length() > maxSize)
		      maxSize = c.length();
		    newArr[i] = c;
		  }
		  
		  for(int i = 0; i < maxSize; i++)
		  {
		    String tempArr[][] = new String[10][newArr.length];
		    for(int j = 0; j < newArr.length; j++)
		    {
		    	String number = newArr[j];
		    	char digit = '0';
		    	try {
		    		digit = number.charAt(number.length() - 1 - i);
		    		//System.out.println("Digit:" + digit + " on number " + newArr[j]);
		    	} catch (StringIndexOutOfBoundsException e){
		    		//System.out.println("Caught error: LOL LONGER THAN NUMBER");
		    		digit = '0';
		    	} catch (NullPointerException e){
		    		System.out.println("Caught error: NPE");
		    		digit = '0';
		    	}
		    	boolean slot = false;
		    	int k = 0;
		    	int pos = Integer.valueOf(Character.toString(digit)).intValue(); 
		    	while (slot != true ){
		    		if (tempArr[pos][k] == null) 
		    			slot = true;
		    		else
		    			k++;
		    	}
		    	//System.out.println("Chose spot " + k + " using digit " + digit + " to store " + number);
		    	tempArr[pos][k] = number;
		    }
		    newArr = this.flatten(tempArr, newArr.length);
		  
		  }
		  
		  for(int i = 0; i < arr.length; i++)
		  {
		    arr[i] = Integer.valueOf(newArr[i]).intValue();
		  }
		  return arr;
		}
		  
		private String[] flatten(String[][] t, int len) //HARD CODED FOR RADIX
		{
			String[] flat = new String[len];
			int x = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < len; j++)
				{
					if (t[i][j] != null)
					{
						flat[x] = t[i][j];
						x++;
					} else {
						break;
					}
				}
			}
			return flat;
		}
		

		
		private void swap (int A[], int x, int y)
		   {
		      int temp = A[x];
		      A[x] = A[y];
		      A[y] = temp;
		   }

		/*
		   private int partition(int A[], int f, int l)
		   {
		      int pivot = A[f];
		      int pp = f;
		      while (f < l)
		      {
		         while (A[f] < pivot) f++;
		         while (A[l] > pivot) l--;
		         swap (A, f, l);
		      }
		      return f;
		   }

		   public int[] quicksort(int A[], int f, int l)
		   {
		      if (f >= l) return A;
		      int pivot_index = partition(A, f, l);
		      quicksort(A, f, pivot_index);
		      return quicksort(A, pivot_index+1, l);
		   }
		  */
		
		public int[] quicksort(int[] arr)
		{
			LinkedList<Integer> lol = new LinkedList<Integer>();
			for (int i = 0; i < arr.length; i++)
				lol.add(arr[i]);
			return toArray(quicksort(lol));
		}
		
		public LinkedList<Integer> quicksort(LinkedList<Integer> a) {
		
			if (a.size() <= 1) 
				return a;
			LinkedList<Integer> less = new LinkedList<Integer>();
			LinkedList<Integer> equal = new LinkedList<Integer>();
			LinkedList<Integer> more = new LinkedList<Integer>();
			int pivot = a.getFirst();
			for(int i = 0; i < a.size(); i++)
			{
				if (a.get(i) < pivot) less.add(a.get(i));
				if (a.get(i) == pivot) equal.add(a.get(i));
				if (a.get(i) > pivot) more.add(a.get(i));
			}
			
			LinkedList<Integer> temp = lMerge(quicksort(less), equal);
			return lMerge(temp,quicksort(more));
	    }
		
		private LinkedList<Integer> lMerge(LinkedList<Integer> a, LinkedList<Integer> b)
		{
			for (int i = 0; i < b.size(); i++)
				a.add(b.get(i));
			return a;
		}
		
		private int[] toArray(LinkedList<Integer> a)
		{
			int[] tmp = new int[a.size()];
			for(int i = 0; i < a.size(); i++)
				tmp[i] = a.get(i);
			return tmp;
		}
		
		
		
		
		  
		  public int[] mergesort(int[] arr)
		  {
			  //check length. if less than or equal to 1 then return, we're done here
			  if (arr.length <= 1) return arr;
			  
			  //get the middle...
			  int mid = (arr.length / 2);
			  
			  //make left array
			  int[] left = new int[mid];
			  //make right array
			  int[] right = new int[arr.length - mid];
			  //take everything from the first half and put it in the left!
			  for(int i = 0; i < mid; i++)
				  left[i] = arr[i];
			  //same for the right
			  for(int i = mid; i < arr.length; i++)
				  right[i-mid] = arr[i];
			  
			  int[] nleft = mergesort(left);
			  int[] nright = mergesort(right);
			  return merge(nleft,nright);
		  }
		  
		  private int[] merge(int[] left, int[] right)
		  {
			  
			  int length = left.length + right.length;
			  int[] result = new int[length];
			  int i = 0, j = 0, k = 0;
			  while ((i < left.length) && (j < right.length))
			  {
				  if (left[i] < right[j])
				    {
				      result[k] = left[i];
				      i++; k++;
				    }else{
				      result[k] = right[j];
				      j++; k++;
				    } 
			  }
			  if(i < (left.length))
				  for(int x = i; x < left.length; x++)
				  {
					  result[k] = left[x];
					  k++;
				  }
			  if(j < (right.length))
				  for(int x = j; x < right.length; x++)
				  {
					  result[k] = right[x];
					  k++;
				  }
			  
		  	return result;
 		}
		  
		  
		public int[] bubblesort(int[] arr)
		{
			boolean working = true;
			while (working) {
				working = false;
				for(int i = 0; i < arr.length - 1; i++)
				{
					if (arr[i] > arr[i+1])
					{
						int temp = arr[i];
						arr[i] = arr[i+1];
						arr[i+1] = temp;
						working = true;
					}
				}
			}
			return arr;
		}
}
