#include "modules.h"

int adminApp(User *user) {
	return EXIT_OPTION;
}
//modules
int mainApp(User *user) {
	if (user->role == ROLE_ADMIN)
		return adminApp(user);

	return userApp(user);
}
//user
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