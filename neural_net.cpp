#include<iostream>
#include<string>

const double LEARNING_RATE = 0.5;

class Node
{
public:
	std::string name;
	double * weight;
	double output;
	int weightCount;
};

class Net
{
private:
	int layerCount;
	int * layerNodeCount;
	Node ** node;
	double * testOutput;
	double * error;
public:
	//void load(string loadFile);
	void create(int * netTopology);
	//void feedForward();
	//void getError();
	//void backPropagate();
};

//void Net::load(string loadFile)
//{
//
//}
//
void Net::create(int * netTopology)
{
	// Hardcoding the layerCount to 3 for now
	layerCount = 3;

	layerNodeCount = new int[layerCount];

	//Set each layer's node count to the value supplied by the topology
	int max = 0; //This will be used to find the maximum number of nodes in a layer
	for (int x = 0; x < layerCount; x++)
	{
		if (netTopology[x] > max)
		{
			max = netTopology[x];
		}
	}

	//Create a 2D array of Nodes 
	Node** node = new Node*[layerCount];
	for (int i = 0; i < layerCount; i++)
	{
		node[i] = new Node[netTopology[i]];
	}

	for (int x = 0; x < layerCount; x++)
	{
		for (int y = 0; y < netTopology[x]; y++)
		{
			node[x][y].name = "Node" + std::to_string(x) + "." + std::to_string(y);
			std::cout << node[x][y].name << std::endl;
		}
	}
}

//void Net::feedForward()
//{
//
//}
//
//void Net::getError()
//{
//
//}
//
//void Net::backPropagate()
//{
//
//}

int main()
{
	Net NeuralNet;

	//Prompt user to load a network
	std::string response;
	std::string fileName;
	int topology[3];
	int layerCount;
	std::cout << "Would you like to load a network?  (Y/N)\n";
	std::getline(std::cin, response);
	
	if (response == "Y")
	{
		std::cout << "What file would you like to load?\n";
		std::getline(std::cin, fileName);
		//NeuralNet.load(fileName);
	}
	//If the user doesn't want to load a network, see if they want to create one
	else if (response == "N")
	{
		std::cout << "Would you like to create a new network? (Y/N)\n";
		std::getline(std::cin, response);
		if (response == "Y")
		{
			std::cout << "Input topology.  (Ex: Enter 20 30 1 for 20 input nodes, 30 hidden nodes, and 1 output node)\n";
			// Get 3 values from cin because this program only supports 3 layers for the neural network
			for (int i = 0; i < 3; i++)
			{
				std::cin >> topology[i];
			}
			NeuralNet.create(topology);
		}
		else
		{
			std::cout << "Understood.  Exiting program.\n";
			exit(0);
		}
	}
	else
	{
		std::cout << "\nInvalid response entered.  Exiting program.\n";
		system("pause");
		exit(0);
	}

	//NeuralNet.feedForward();
	//NeuralNet.getError();
	//NeuralNet.backPropagate();

	//std::cout << "Wut";
	//system("pause>nul");

	system("pause");
	return 0;
}
