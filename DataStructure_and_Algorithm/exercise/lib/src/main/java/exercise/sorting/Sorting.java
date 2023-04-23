package exercise.sorting;

import java.util.ArrayList;
import java.util.Arrays;

public class Sorting {
	public int binarySearch(ArrayList<Integer> arr, int start, int end, int data) {
		if(arr.isEmpty()&&arr.size()==0)
			return -1;
		else if(end==start) {
			if(arr.get(start)==data)
				return start;
			else 
				return -1;
		}else {
			int piviot = (end+start)/2;
			if(arr.get(piviot) == data) 
				return piviot;
			else if(arr.get(piviot) > data)
				return binarySearch(arr, start, piviot, data);
			else 
				return binarySearch(arr, piviot, end, data);
		}
	}
	
	public static void selectionSort(ArrayList<Integer> arr) {
		if(arr.isEmpty()&&arr.size()==0) 
			return;
		
		for(int i = 0; i < arr.size()-1; i++) {
			int least = i;
			
			for(int j=i+1; j<arr.size(); j++) {
				if(arr.get(j) < arr.get(least))
					least = j;
			}
			
			if(i != least) {
				int temp = arr.get(i);
				arr.set(i, arr.get(least));
				arr.set(least, temp);
			}
		}
	}
	
	public static void insertionSort(ArrayList<Integer> arr) {
		 for(int i = 1 ; i < arr.size() ; i++){
			 int key = arr.get(i);
			 int j = i-1;
			 
			 for(; j>=0&& arr.get(j)>key; j--) {
				 arr.set(j+1, arr.get(j));
			 }
			 
			 arr.set(j+1,key);
		 }
	}
	
	public static void mergeSort(ArrayList<Integer> arr, int start, int end) {
		//from here
	}
	
	//copy : [start, end)
	private static ArrayList<Integer> partCopy(ArrayList<Integer> arr, int start, int end){
		Integer[] array = arr.toArray(new Integer[arr.size()]);
		Integer[] partial_copied = Arrays.copyOfRange(array, start, end);
		
		ArrayList<Integer> arrayList = new ArrayList<>();
		for(Integer temp : partial_copied){
		  arrayList.add(temp);
		}
		
		return arrayList;
	}		
	
	
}
