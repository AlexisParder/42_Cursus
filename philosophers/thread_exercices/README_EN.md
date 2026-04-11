[🇫🇷 French](./README.md)
- [📘 PART 1: Mastering Threads](#-part-1-mastering-threads)
  - [Exercise 1.1: My first thread](#exercise-11-my-first-thread)
    - [Goal: Create and wait for a simple thread](#goal-create-and-wait-for-a-simple-thread)
      - [Instructions](#instructions)
      - [Constraints](#constraints)
      - [Results](#results)
  - [Exercise 1.2: Multiple threads](#exercise-12-multiple-threads)
    - [Goal: Manage multiple threads with IDs](#goal-manage-multiple-threads-with-ids)
      - [Instructions](#instructions-1)
      - [Constraints](#constraints-1)
      - [Pitfall to avoid](#pitfall-to-avoid)
  - [Exercise 1.3: Thread with return value](#exercise-13-thread-with-return-value)
    - [Goal: Retrieve a result from a thread](#goal-retrieve-a-result-from-a-thread)
      - [Instructions:](#instructions-2)
      - [Constraints:](#constraints-2)
      - [To understand:](#to-understand)
  - [Exercise 1.4: pthread\_detach](#exercise-14-pthread_detach)
    - [Goal: Understand the difference between join and detach](#goal-understand-the-difference-between-join-and-detach)
      - [Instructions:](#instructions-3)
      - [Constraints:](#constraints-3)
      - [Required functions:](#required-functions)
      - [To understand:](#to-understand-1)
  - [Exercise 1.5: Measuring time](#exercise-15-measuring-time)
    - [Goal: Master gettimeofday](#goal-master-gettimeofday)
      - [Instructions:](#instructions-4)
      - [Constraints:](#constraints-4)
      - [Required functions:](#required-functions-1)
      - [To understand:](#to-understand-2)
- [📗 PART 2: Threads + Mutex](#-part-2-threads--mutex)
  - [Exercise 2.1: The problem without mutex](#exercise-21-the-problem-without-mutex)
    - [Goal: Visualize a race condition](#goal-visualize-a-race-condition)
      - [Instructions:](#instructions-5)
      - [Constraints:](#constraints-5)
      - [Required functions:](#required-functions-2)
      - [To understand:](#to-understand-3)
  - [Exercise 2.2: Solving with a mutex](#exercise-22-solving-with-a-mutex)
    - [Goal: Protect a shared resource](#goal-protect-a-shared-resource)
      - [Instructions:](#instructions-6)
      - [Constraints:](#constraints-6)
      - [Required functions:](#required-functions-3)
      - [To understand:](#to-understand-4)
  - [Exercise 2.3: Mutex and printing](#exercise-23-mutex-and-printing)
    - [Goal: Protect prints to avoid mixed output](#goal-protect-prints-to-avoid-mixed-output)
      - [Instructions:](#instructions-7)
      - [Constraints:](#constraints-7)
      - [Required functions:](#required-functions-4)
      - [To understand:](#to-understand-5)
  - [Exercise 2.4: Multiple mutexes](#exercise-24-multiple-mutexes)
    - [Goal: Manage multiple independent resources](#goal-manage-multiple-independent-resources)
      - [Instructions:](#instructions-8)
      - [Constraints:](#constraints-8)
      - [Required functions:](#required-functions-5)
      - [⚠️ Pitfall:](#️-pitfall)
  - [Exercise 2.5: Detecting and preventing deadlock](#exercise-25-detecting-and-preventing-deadlock)
    - [Goal: Solve the deadlock from exercise 2.4](#goal-solve-the-deadlock-from-exercise-24)
      - [Instructions:](#instructions-9)
      - [Hint:](#hint)
      - [Required functions:](#required-functions-6)
      - [To understand:](#to-understand-6)


# 📘 PART 1: Mastering Threads
## Exercise 1.1: My first thread

### Goal: Create and wait for a simple thread

#### Instructions
1. Create a thread that prints `Hello from thread!` 5 times
2. Main prints `Hello from main!` 5 times
3. Main waits for the thread to finish
4. Print `Program finished`

#### Constraints
- Use `pthread_create()`
- Use `pthread_join()`
- No global variables

#### Results
Main and thread messages interleave (non-deterministic order)

## Exercise 1.2: Multiple threads

### Goal: Manage multiple threads with IDs

#### Instructions
1. Take an argument `N` (number of threads)
2. Create `N` threads
3. Each thread prints its ID (0, 1, 2...) 3 times
   - Format: `Thread 2: message 1`
4. Main waits for all threads
5. Print how many threads were created

#### Constraints
- Use an array of `pthread_t`
- Pass the ID to each thread
- `join` all threads

#### Pitfall to avoid
```c
// ❌ WRONG:
for (int i = 0; i < n; i++)
    pthread_create(&threads[i], NULL, routine, &i);
// &i is shared! All threads see the same address

// ✅ CORRECT:
// Allocate a unique ID per thread or use a struct
```

## Exercise 1.3: Thread with return value

### Goal: Retrieve a result from a thread

#### Instructions:
1. Create 5 threads
2. Each thread computes the sum of the first `N` numbers
    - Thread 0: sum from 1 to 100
    - Thread 1: sum from 101 to 200
    - Thread 2: sum from 201 to 300...
3. Main retrieves each result with `pthread_join()`
4. Print the total sum

#### Constraints:
- Use the second parameter of pthread_join() to retrieve the value
- Allocate memory for the return value correctly

#### To understand:
How to return a value from a thread?

## Exercise 1.4: pthread_detach

### Goal: Understand the difference between join and detach

#### Instructions:
- Create 3 detached threads
- Each thread prints its ID then waits 1 second (`usleep`)
- Main prints `Main finished` and exits
- Observe what happens

#### Constraints:
- Use `pthread_detach()`
- Use `usleep()`

#### Required functions:
`pthread_create`, `pthread_detach`, `usleep`, `printf`

#### To understand:
- What happens if main exits before the detached threads finish?
- What is the fundamental difference with pthread_join?

## Exercise 1.5: Measuring time

### Goal: Master gettimeofday

#### Instructions:
- Create a get_time_ms() function that returns the time in milliseconds
- Create 3 threads
- Each thread prints:
  - Thread 0 started at: 0ms
  - Thread 0 finished at: 150ms
- Each thread simulates work with usleep

#### Constraints:
- Use `gettimeofday()`
- Calculate time relative to program start
- No absolute clock in the output

#### Required functions:
`pthread_create`, `pthread_join`, `gettimeofday`, `usleep`, `printf`

#### To understand:
- struct timeval tv;
  - gettimeofday(&tv, NULL);
  - long ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
- How to calculate a relative time?
- Why avoid time() which only gives seconds?

# 📗 PART 2: Threads + Mutex

## Exercise 2.1: The problem without mutex

### Goal: Visualize a race condition

#### Instructions:
- Create a global variable int counter = 0
- Launch 5 threads
- Each thread increments counter 10,000 times
- Main prints the final value
- Expected result: 50,000
- Actual result: ???

#### Constraints:
- DO NOT use a mutex (that's the point!)
- Run the program multiple times

#### Required functions:
`pthread_create`, `pthread_join`, `printf`

#### To understand:
- Why is the result different each time?
- What is a race condition?

## Exercise 2.2: Solving with a mutex

### Goal: Protect a shared resource

#### Instructions:
- Take exercise 2.1
- Add a mutex to protect the increment
- The result must always be 50,000

#### Constraints:
- Use `pthread_mutex_init()`
- Use `pthread_mutex_lock()` / `pthread_mutex_unlock()`
- Use `pthread_mutex_destroy()`
- Always destroy the mutex at the end

#### Required functions:
`pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`, `printf`

#### To understand:
```c
// Critical section
pthread_mutex_lock(&mutex);
counter++;              // Only one thread at a time here
pthread_mutex_unlock(&mutex);
```

## Exercise 2.3: Mutex and printing

### Goal: Protect prints to avoid mixed output

#### Instructions:
- Create 5 threads
- Each thread prints 3 messages with a timestamp:
  - [42ms] Thread 2: eating
  - [43ms] Thread 2: sleeping
  - [44ms] Thread 2: thinking
- Lines must never be mixed together

#### Constraints:
- A mutex dedicated only to prints
- Use `gettimeofday()` for the timestamp
- Each complete printf must be atomic

#### Required functions:
`pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`, `gettimeofday`, `printf`

#### To understand:
- Why do even prints need to be protected?

## Exercise 2.4: Multiple mutexes

### Goal: Manage multiple independent resources

#### Instructions:
- Create 5 forks (5 mutexes)
- Launch 5 threads (philosophers)
- Each philosopher needs 2 forks to eat
- Philosopher i picks up fork i and fork i+1
- Each philosopher eats 3 times then finishes
- Print when they pick up/put down each fork

#### Constraints:
- An array of mutexes: pthread_mutex_t forks[5]
- No deadlock (for now, don't worry about it)
- Use `usleep()` to simulate eating/thinking

#### Required functions:
`pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`, `usleep`, `gettimeofday`, `printf`

#### ⚠️ Pitfall:
- This exercise can cause a deadlock
- Observe under what conditions it appears
- This is exactly the Philosophers problem!

## Exercise 2.5: Detecting and preventing deadlock

### Goal: Solve the deadlock from exercise 2.4

#### Instructions:
    Take exercise 2.4
    Find a strategy to avoid deadlock

#### Hint:
- Even-numbered philosophers pick up left then right
- Odd-numbered philosophers pick up right then left

#### Required functions:
`pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`, `usleep`, `gettimeofday`, `printf`

#### To understand:
- Why is the order of mutex acquisition crucial?
- What other strategies exist?
