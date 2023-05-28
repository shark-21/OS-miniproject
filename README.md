[![Anurag’s github stats](https://github-readme-stats.vercel.app/api?username=shark-21)](https://github.com/shark-21)

[![Top Langs](https://github-readme-stats.vercel.app/api/top-langs/?username=shark-21&layout=compact)](https://github.com/shark-21)


IMPLEMENTATION :
❖ The given code implements the Banker's algorithm in C++ language. The code
takes input from the user, such as the number of users and the number of
resources, available resources, resource allocation, and maximum allocation.
The code then calculates the need of each user by subtracting the allocation
from the maximum allocation. Then, the code checks whether the current state is
safe or not by simulating the allocation and releasing the resources of each
process one by one until all processes are completed. If the system can allocate
resources to all processes safely, then it returns the safe sequence. Otherwise, it
returns deadlock.
❖ The code also provides an option to the user to display the current state of the
system, and it also allows the user to make additional requests. The user can
enter the process ID and the request. If the system can allocate the resources
safely, then the request is accepted, and the system checks for deadlock again. If
the system cannot allocate the resources safely, the request is rejected.
