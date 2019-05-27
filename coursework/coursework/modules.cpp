#include "modules.h"

int mainApp(User *user) {
	return (user->role == ROLE_ADMIN_VALUE || user->role == ROLE_SUPER_ADMIN_VALUE)
		? adminApp(user)
		: userApp(user);
}
int userApp(User *user) {
	int choice;
	while (1) {
		cout << "Login: " << user->login << '\n' <<
			"Choose what you want:\n"
			" 1.view all data about workers\n"
			" 2.calculate the wages of all employees for a certain period of time\n"
			" 3.search data about workers\n"
			" 4.sort data about workers\n"
			" 5.logout(back to auth)\n"
			" 0.exit\n";
		choice = readIntNum();
		system("cls");

		switch (choice) {
		case EXIT_OPTION:
			return EXIT_OPTION;
		case 1:
			viewAllWorkers();
			break;
		case 2:
		{
			cout << "Input date range(valid ranges: 1.2, 0.18, 2.0)\n";
			char range[DATE_SIZE];
			strcpy(range, getRange());

			int num;
			Worker *workers = new Worker[MAX_ARRAY_SIZE];
			readAllWorkers(workers, num);

			calcAndCoutSalariesForRange(workers, num, range);
			break;
		}
		case 3:
		{
			do {
				cout << "Choose parameter for search:\n"
					" 1.personal number\n"
					" 2.date\n"
					" 3.fio\n"
					" 0.back\n";
				choice = readIntNum();
				system("cls");
			} while (choice < 0 || choice > 3);

			if (choice != 0) {
				int num;
				Worker *workers = new Worker[MAX_ARRAY_SIZE];
				readAllWorkers(workers, num);

				searchWorkers(workers, num, choice);
			}
			break;
		}
		case 4:
		{
			do {
				cout << "Choose parameter for sort:\n"
					" 1.personal number\n"
					" 2.date\n"
					" 3.fio\n"
					" 0.back\n";
				choice = readIntNum();
				system("cls");
			} while (choice < 0 || choice > 3);

			if (choice != 0) {
				int num;
				Worker *workers = new Worker[MAX_ARRAY_SIZE];
				readAllWorkers(workers, num);

				sortWorkers(workers, num, choice);
			}
			break;
		}
		case 5:
		{
			int choice;
			User *user = new User;
			while (auth(choice, user));
			return EXIT_OPTION;
		}
		default:
			cout << "Unknown option: " << choice << '\n';
		}

		doPauseAndCls();
	}
}
int adminApp(User *user) {
	int choice;
	while (1) {
		cout << "Login: " << user->login << '\n' <<
			"Choose what you want:\n"
			" 1.work with workers\n"
			" 2.work with users\n"
			" 3.logout(back to auth)\n"
			" 0.exit\n";
		choice = readIntNum();
		system("cls");

		switch (choice) {
		case EXIT_OPTION:
			return EXIT_OPTION;
		case 1:
			while(adminAppWorkers(user, choice));
			break;
		case 2:
		{
			while(adminAppUsers(user, choice));
			break;
		}
		case 3:
		{
			User *user = new User;
			while (auth(choice, user));
			return EXIT_OPTION;
		}
		default:
			cout << "Unknown option: " << choice << '\n';
		}

		if (choice != EXIT_OPTION)
			doPauseAndCls();
	}
}
int adminAppWorkers(User *user, int &choice) {
	while (1) {
		cout << "Login: " << user->login << '\n' <<
			"Choose what you want:\n"
			" 1.add worker\n"
			" 2.view all data about workers\n"
			" 3.edit worker info\n"
			" 4.remove worker info\n"
			" 5.calculate the wages of all workers for a certain period of time\n"
			" 6.search data about workers\n"
			" 7.sort data about workers\n"
			" 0.back\n";
		choice = readIntNum();
		system("cls");

		switch (choice) {
		case EXIT_OPTION:
			return EXIT_OPTION;
		case 1:
			addWorker();
			break;
		case 2:
			viewAllWorkers();
			break;
		case 3:
			editWorker();
			break;
		case 4:
			deleteWorker();
			break;
		case 5:
		{
			cout << "Input date range(valid ranges: 1.2, 0.18, 2.0)\n";
			char range[DATE_SIZE];
			strcpy(range, getRange());

			int num;
			Worker *workers = new Worker[MAX_ARRAY_SIZE];
			readAllWorkers(workers, num);

			calcAndCoutSalariesForRange(workers, num, range);
			break;
		}
		case 6:
		{
			do {
				cout << "Choose parameter for search:\n"
					" 1.personal number\n"
					" 2.date\n"
					" 3.fio\n"
					" 0.back\n";
				choice = readIntNum();
				system("cls");
			} while (choice < 0 || choice > 3);

			if (choice != 0) {
				int num;
				Worker *workers = new Worker[MAX_ARRAY_SIZE];
				readAllWorkers(workers, num);

				searchWorkers(workers, num, choice);
			}
			break;
		}
		case 7:
		{
			do {
				cout << "Choose parameter for sort:\n"
					" 1.personal number\n"
					" 2.date\n"
					" 3.fio\n"
					" 0.back\n";
				choice = readIntNum();
				system("cls");
			} while (choice < 0 || choice > 3);

			if (choice != 0) {
				int num;
				Worker *workers = new Worker[MAX_ARRAY_SIZE];
				readAllWorkers(workers, num);

				sortWorkers(workers, num, choice);
			}
			break;
		}
		default:
			cout << "Unknown option: " << choice << '\n';
		}

		doPauseAndCls();
	}
}
int adminAppUsers(User *user, int &choice) {
	while (1) {
		cout << "Login: " << user->login << '\n' <<
			"Choose what you want:\n"
			" 1.add user\n"
			" 2.view all data about users\n"
			" 0.back\n";
		choice = readIntNum();
		system("cls");

		switch (choice) {
		case EXIT_OPTION:
			return EXIT_OPTION;
		case 1:
			addUser(user->role);
			break;
		case 2:
			viewAllUsers();
			break;
		default:
			cout << "Unknown option: " << choice << '\n';
		}

		doPauseAndCls();
	}
}