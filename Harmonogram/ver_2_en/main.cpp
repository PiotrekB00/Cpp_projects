#include "time.hpp"
#include "schedule.hpp"

int main() {
	Time time1(30, 40, 2), time2(28, 1), time3(84), time4, time_sum, time_range, user_time;
	Schedule schedule1, schedule2, schedule3;
	unsigned int x, y, h, m, s, tmp_time_nr;

	time1 = time1 + time2;
	time3 = time3 + 5;
	time4 = time4 + 66;

	schedule1.add_time(time1);
	schedule1.add_time(time2);
	schedule1.add_time(time3);
	schedule1.add_time(time4);

	while (1) {
		std::cout << "Schedule" << '\n'
			<< "1 - show times" << '\n'
			<< "2 - add time" << '\n'
			<< "3 - show number of times" << '\n'
			<< "4 - choose time to display" << '\n'
			<< "5 - sum times" << '\n'
			<< "6 - copy n times" << '\n'
			<< "7 - add copy to schedule with range" << '\n'
			<< "8 - add seconds to selected time" << '\n';
		std::cin >> x;
		if (std::cin.fail() == true) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		switch (x) {
		case 1:
			system("cls");
			schedule1.display_schedule();
			break;
		case 2:
			system("cls");
			user_time.enter_time(user_time);
			schedule1.add_time(user_time);
			break;
		case 3:
			system("cls");
			schedule1.return_numbers_of_time();
			std::cin.get();
			break;
		case 4:
			system("cls");
			schedule1.display_schedule();

			do {
				std::cout << "choose time to display " << '\n';
				std::cin >> y;
			} while (y > schedule1.get_time_numbers() or y <= 0);

			schedule1.return_time(y);
			break;
		case 5:
			system("cls"); 
			schedule1.display_schedule();
			time_sum = schedule1.sum_times(time_sum);
			time_sum.display_time();
			break;
		case 6:
			system("cls");
			schedule1.display_schedule();

			do {
				std::cout << "to which time u want copy " << '\n';
				std::cin >> y;
			} while (y > schedule1.get_time_numbers() or y <= 0);

			tmp_time_nr = schedule1.get_time_numbers();
			schedule1.set_time_numbers(y);
			schedule3 = schedule1;
			schedule3.display_schedule();
			schedule1.set_time_numbers(tmp_time_nr);
			break;
		case 7:
			system("cls");
			time_range.enter_time(time_range);
			schedule1.sum_times(time_sum);

			if (time_sum < time_range or time_sum == time_range) {
				schedule2 = schedule1;
			}
			else {
				schedule2 = schedule1.copy_to_range(time_range);
			}

			schedule2.display_schedule();
			break;
		case 8:
			system("cls");
			//TODO
			break;
		default:
			system("cls");
			std::cout << "enter a number " << '\n';
			break;
		}
	}

	return 0;
}