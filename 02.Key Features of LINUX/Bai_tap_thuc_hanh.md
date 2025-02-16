### Làm việc với Kernel Modules ###
Đề bài: 
* Kiểm tra các module kernel đang chạy: lsmod
* Xem thông tin về một module cụ thể: modinfo ext4

-----

lsmod & modinfo ext4
![This is result of lsmod and modinfo ext4](4.Kernel-Modules.png)


### Quản lý tiến trình trong Linux ###
Đề bài:
* Liệt kê tất cả tiến trình đang chạy: ps aux
* Xem thông tin tiến trình theo thời gian thực: top
* Kết thúc một tiến trình cụ thể: kill -9 <PID>

* Hướng dẫn làm:

	Kiểm tra PID bằng ps aux trước khi dùng kill.

	Quan sát thay đổi trước và sau khi kill tiến trình.

-----

ps aux
![This is result of ps aux](4.ps-aux.png)

top
![This is result of top](4.top.png)
	
kill -9 <PID>
![This is result of kill -9 <PID>](4.kill-9.png)


### Tạo và quản lý thread trong Linux bằng C ###
Bài tập:
* Viết chương trình tạo 3 thread in ra thông điệp.
* Sử dụng pthread_create(), pthread_join().
* Kiểm tra ID của từng thread.
* Hướng dẫn làm:

	Cài đặt gcc nếu chưa có (sudo apt install gcc).
	
	Biên dịch chương trình với -lpthread.

	Quan sát thứ tự thực thi của các thread.
	
-----

[`manage_threads_in_linux.c`](manage_threads_in_linux.c)
![This is result of compiling & running manage_threads_in_linux.c](5.pthread.png)


### Lập trình với Preemptive Scheduling ### 
Bài tập:
* Viết chương trình tạo 2 tiến trình con.
* Dùng nice để điều chỉnh mức độ ưu tiên.
* Kiểm tra mức ưu tiên bằng ps -eo pid,pri,ni,cmd.
* Hướng dẫn làm:

	Thử chạy tiến trình với nice -n 10 ./program.
	
	Quan sát xem tiến trình nào chạy nhanh hơn.
	
-----

[`preemptive_scheduling.c`](preemptive_scheduling.c)
![This is result of compiling & running preemptive_scheduling.c](6.preemptive-scheduling.png)