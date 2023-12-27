#include <iostream> 
using namespace std;

class Application
{
	static Application* instance;
	string title;

	// private: 
	Application()
	{
		title = "God's Menu";
	}

public:
	static Application* GetInstance()
	{
		return instance == nullptr ? instance = new Application() : instance;
	}

	void StartRandomize()
	{
		srand(static_cast<unsigned>(time(nullptr)));
		int random_number = rand() % 100 + 1;
		cout << "Random number: " << random_number << endl;
	}

	string GetTitle() const
	{
		return title;
	}

	void SetTitle(string title)
	{
		this->title = title;
	}

};

Application* Application::instance = nullptr;

int main()
{
	Application* ptr = Application::GetInstance();
	cout << ptr->GetTitle() << "\n";
	ptr->SetTitle("Super Bowl");
	cout << ptr->GetTitle() << "\n";
	ptr->StartRandomize();
}