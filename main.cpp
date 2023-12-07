#include <iostream>
#include <string>
#include <vector>

#include "concrete_handlers.h"
#include "concrete_handler_human.h"


/**
* The client code is usually suited to work with a single handler. In most
* cases, it is not even aware that the handler is part of a chain.
*/
void ClientCode(Handler& handler) {
	std::vector<std::string> food = { "Nut", "Banana", "Cup of coffee" };
	for (const std::string& f : food) {
		std::cout << "Client: Who wants a " << f << "?\n";
		const std::string result = handler.Handle(f);
		if (!result.empty()) {
			std::cout << "  " << result;
		}
		else {
			std::cout << "  " << f << " was left untouched.\n";
		}
	}
}
/**
* The other part of the client code constructs the actual chain.
*/
int main() {
	HumanHandler* human = new HumanHandler;
	MonkeyHandler* monkey = new MonkeyHandler;
	SquirrelHandler* squirrel = new SquirrelHandler;
	DogHandler* dog = new DogHandler;
	monkey->SetNext(squirrel)->SetNext(dog)->SetNext(human);

	/**
	* The client should be able to send a request to any handler, not just the
	* first one in the chain.
	*/
	std::cout << "Chain: Monkey > Squirrel > Dog > Human\n\n";
	ClientCode(*monkey);
	std::cout << "\n";
	std::cout << "Subchain: Squirrel > Dog > Human\n\n";
	ClientCode(*squirrel);
	std::cout << "Subchain: Dog > Human\n\n";
	ClientCode(*dog);

	delete monkey;
	delete squirrel;
	delete dog;
	delete human;
	return 0;
}