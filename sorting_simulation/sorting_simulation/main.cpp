#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include <deque>

#define ARR_SIZE 600

//draw
void draw(int* arr, sf::RenderWindow& window) {
	for (int i = 0; i < ARR_SIZE; i++) {
		sf::Vertex toDraw[2] = {
			sf::Vertex(sf::Vector2f(i, 600.0f), sf::Color::Blue), //x is right dir, y is downward(left top corner is standard)
			sf::Vertex(sf::Vector2f(i, 600-arr[i]), sf::Color::Blue)
		};

		window.draw(toDraw, 2, sf::Lines);
	}
}

//catch frame
void snap(int* arr, std::deque<int*>& frames) {
	int* frame = (int*)malloc(sizeof(int)*600);

	for (int i = 0; i < ARR_SIZE; i++)
		frame[i] = arr[i];

	frames.push_back(frame);
}

//clear frames
void clear(std::deque<int*>& frames) {
	while (!frames.empty()) {
		free(frames.back());
		frames.pop_back();
	}
}

//swap indexes
void swap(int* arr, int index_1, int index_2) {
	int temp = arr[index_2];
	arr[index_2] = arr[index_1];
	arr[index_1] = temp;
}

//shuffle
void shuffle(int* arr, std::deque<int*>& frames) {

	std::cout << "Now Shuffling!! : ";

	for (int i = 0; i < ARR_SIZE * 3; i++) {
		int index_1 = rand() % 600;
		int index_2 = rand() % 600;

		swap(arr, index_1, index_2);

		snap(arr, frames);
	}
}

//bubble sort
void bubble_sort(int* arr, std::deque<int*>& frames) {
	for (int i = ARR_SIZE - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr, j, j+1);
			}
			snap(arr, frames);
		}
	}
}

//selection sort
void selection_sort(int* arr, std::deque<int*>& frames) {
	for (int i = 0; i < ARR_SIZE - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < ARR_SIZE; j++) {
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
			snap(arr, frames);
		}
		swap(arr, i, min_index);
	}
}

//insertion sort
void insertion_sort(int* arr, std::deque<int*>& frames) {
	int i, j, key;
	for (i = 1; i < ARR_SIZE; i++) {
		int key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
			snap(arr, frames);
		}
		arr[j + 1] = key;
	}
}
//merge sort
void merge(int* arr, int left, int mid, int right, std::deque<int*>& frames) {
	int* buffer = (int*)malloc(sizeof(int)*ARR_SIZE);
	for (int i = 0; i < ARR_SIZE; i++)
		buffer[i] = arr[i];

	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;

	while(i <= mid && j <= right) {
		if (arr[i] < arr[j])
			buffer[k++] = arr[i++];
		else
			buffer[k++] = arr[j++];

		snap(buffer, frames);
	}

	if (i > mid) {
		for (; j <= right; j++) {
			buffer[k++] = arr[j];
		}
	}
	else {
		for (; i <= mid; i++) {
			buffer[k++] = arr[i];
		}
	}

	snap(buffer, frames);

	for (int i = left; i <= right; i++) {
		arr[i] = buffer[i];
	}

	free(buffer);
}

void merge_sort(int* arr, int left, int right, std::deque<int*>& frames) {
	if(left < right) {
		int piviot = (right + left) / 2;
		merge_sort(arr, left, piviot, frames);
		merge_sort(arr, piviot+1, right, frames);
		merge(arr, left, piviot, right, frames);
	}
}

//quick sort
int partition(int* arr, int left, int right, std::deque<int*>& frames) {
	int low, high, pivot;

	low = left;
	high = right + 1;
	pivot = arr[left];

	do {
		/* list[low]가 피벗보다 작으면 계속 low를 증가 */
		do {
			low++; // low는 left+1 에서 시작
		} while (low <= right && arr[low] < pivot);

		/* list[high]가 피벗보다 크면 계속 high를 감소 */
		do {
			high--; //high는 right 에서 시작
		} while (high >= left && arr[high] > pivot);

		// 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
		if (low < high) {
			swap(arr, low, high);
		}

		snap(arr, frames);
	} while (low < high);

	// low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
	swap(arr, low, high);

	snap(arr, frames);

	return high;
}

void quick_sort(int* arr, int left, int right, std::deque<int*>& frames) {
	if (left < right) {
		int q = partition(arr, left, right, frames);

		quick_sort(arr, left, q-1, frames);
		quick_sort(arr, q+1, right, frames);

		snap(arr, frames);
	}
}

//sort state check : true for completely ordered
bool isSorted(int* arr) {
	for (int i = 0; i < ARR_SIZE - 1; i++) {
		if (arr[i] > arr[i+1]) {
			return false;
		}
	}

	return true; 
}

int main() {
	//variables
	int frames_cnt = 0;

	int arr[ARR_SIZE] = { 0, };
	for (int i = 0; i < ARR_SIZE; i++) {
		arr[i] = i + 1;
	}

	//here is where frames saved
	std::deque<int*> frames;

	char action_type = 0;

	sf::RenderWindow window(sf::VideoMode(600, 600), "Sorting_Simulation", sf::Style::Close|sf::Style::Titlebar);

	bool onDrawing = false;

	std::cout << "Sorting Simulation, Here is instruction!!\n"
		<< "bubble sort : b\n"
		<< "selection sort : s\n"
		<< "insertion sort : i\n"
		<< "merge sort : m\n"
		<< "quick sort : q\n"
		<< "bubble sort : b\n"
		<< "reset : r\n";

	while (window.isOpen()) {

		//user input
		sf::Event event;
		while (window.pollEvent(event)&&!onDrawing) {
			switch (event.type)
			{
			case sf::Event::Closed :
				window.close();
				break;
			case sf::Event::TextEntered:
					//reset
					if (event.text.unicode == 'r') action_type = 'r';
					//bubble sort
					else if (event.text.unicode == 'b') action_type = 'b';
					//selection sort
					else if (event.text.unicode == 's') action_type = 's';
					//insertion sort
					else if (event.text.unicode == 'i') action_type = 'i';
					//merge sort
					else if (event.text.unicode == 'm') action_type = 'm';
					//quick sort
					else if (event.text.unicode == 'q') action_type = 'q';
				break;
			default:
				break;
			}
		}

		window.clear(sf::Color::Black);
		if (action_type != 0 && action_type != 'r') {
			if (!onDrawing) {
				//shuffle
				shuffle(arr, frames);

				//sort here
				if (action_type == 'b') {
					std::cout << "bubble sorting\n";
					bubble_sort(arr, frames);
					frames_cnt = frames.size() - 1800;
					onDrawing = true;
				}
				else if (action_type == 's') {
					std::cout << "selection sorting\n";
					selection_sort(arr, frames);
					frames_cnt = frames.size() - 1800;
					onDrawing = true;
				}
				else if (action_type == 'i') {
					std::cout << "insertion sorting\n";
					insertion_sort(arr, frames);
					frames_cnt = frames.size() - 1800;
					onDrawing = true;
				}
				else if (action_type == 'm') {
					std::cout << "merge sorting\n";
					merge_sort(arr, 0, ARR_SIZE-1, frames);
					frames_cnt = frames.size() - 1800;
					onDrawing = true;
				}
				else if (action_type == 'q') {
					std::cout << "quick sorting\n";
					quick_sort(arr, 0, ARR_SIZE-1, frames);
					frames_cnt = frames.size() - 1800;
					onDrawing = true;
				}
			}
			else {
				if (!frames.empty()) {
					draw(frames.front(), window);
					free(frames.front());
					frames.pop_front();
				}
				else {
					action_type = 'r';
					std::cout << "Frame's count(the more, the slower) : " << frames_cnt << std::endl;
					frames_cnt = 0;
				}
			}
		}
		else if (action_type == 'r') {
			for (int i = 0; i < ARR_SIZE; i++) {
				arr[i] = i + 1;
			}
			draw(arr, window);
			onDrawing = false;
			action_type = 0;
		}
		else if (action_type == 0) {
			draw(arr, window);
		}

		window.display();
	}

	clear(frames);

	return 0;
}