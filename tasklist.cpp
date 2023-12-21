#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.push_back(Task(desc));
        std::cout << "Task added successfully.\n";
    }

    void markTaskAsComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as complete.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

     void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            std::cout << "Tâche supprimée avec succès.\n";
        } else {
            std::cout << "Indice de tâche non valide.\n";
        }
    }

    void displayTasks() const {
        if (tasks.empty()) {
            std::cout << "La liste est vide.\n";
        } else {
            std::cout << "Task List:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << "[" << i + 1 << "] ";
                if (tasks[i].completed) {
                    std::cout << "[Completed] ";
                }
                std::cout << tasks[i].description << "\n";
            }
        }
    }
};

int main() {
    TaskList taskList;
    int choice;

    do {
        std::cout << "\nMenu de l'application :\n";
        std::cout << "1. Ajouter une tâche\n";
        std::cout << "2. Marquer la tâche comme complétée\n";
        std::cout << "3. Afficher toutes mes tâches\n";
        std::cout << "4. Supprimer une tâche\n";
        std::cout << "5. Quitter\n";
        std::cout << "Entrez votre choix (1-5) : ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore();  // Clear the newline character from the buffer
                std::getline(std::cin, description);
                taskList.addTask(description);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter the index of the task to mark as complete: ";
                std::cin >> index;
                taskList.markTaskAsComplete(index - 1);
                break;
            }
            case 3:
                taskList.displayTasks();
                break;
            case 4:
                int index;
                std::cout << "Quelle taches voulez vous suprimmer:" ;
                taskList.displayTasks();
                std::cin >> index;
                taskList.removeTask(index - 1);
                break;
               
            case 5:
                std::cout << "Exiting the program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 5);

    return 0;
}
