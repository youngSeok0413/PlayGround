#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <deque>

#define ARR_SIZE 600

/*
* need to do
* add algorithms(bubble, quick, merge, insertion, selection)
* add sound file and play it while drawing
*/

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
void shuffle(int* arr) {
	for (int i = 0; i < ARR_SIZE * 5; i++) {
		int index_1 = rand() % 600;
		int index_2 = rand() % 600;

		swap(arr, index_1, index_2);
	}
}

//bubble sort
void bubble_sort(int* arr, std::deque<int*>& frames) {
	for (int i = ARR_SIZE - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr, j, j+1);
				snap(arr, frames);
			}
		}
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
				//sort here
				shuffle(arr);
				if (action_type == 'b') {
					std::cout << "bubble sorting\n";
					shuffle(arr);
					bubble_sort(arr, frames);
					onDrawing = true;
				}
				else if (action_type == 's') {
					shuffle(arr);
					onDrawing = true;
				}
				else if (action_type == 'i') {
					shuffle(arr);
					onDrawing = true;
				}
				else if (action_type == 'm') {
					shuffle(arr);
					onDrawing = true;
				}
				else if (action_type == 'q') {
					shuffle(arr);
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