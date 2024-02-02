class Phonebook:
    def __init__(self):
        self.contacts = []

    def insert(self, name, mobile):
        entry = (name, mobile)
        left, right = 0, len(self.contacts) - 1

        while left <= right:
            mid = (left + right) // 2
            if self.contacts[mid][0] == name:
                return "Contact already exists."

            if name < self.contacts[mid][0]:
                right = mid - 1
            else:
                left = mid + 1

        self.contacts.insert(left, entry)
        return "Contact added successfully."

    def recursive_binary_search(self, name, left, right):
        if left > right:
            return None

        mid = (left + right) // 2
        if self.contacts[mid][0] == name:
            return self.contacts[mid]
        elif name < self.contacts[mid][0]:
            return self.recursive_binary_search(name, left, mid - 1)
        else:
            return self.recursive_binary_search(name, mid + 1, right)

    def non_recursive_binary_search(self, name):
        left, right = 0, len(self.contacts) - 1

        while left <= right:
            mid = (left + right) // 2
            if self.contacts[mid][0] == name:
                return self.contacts[mid]
            elif name < self.contacts[mid][0]:
                right = mid - 1
            else:
                left = mid + 1
        return None

    def search(self, name, recursive=True):
        if recursive:
            return self.recursive_binary_search(name, 0, len(self.contacts) - 1)
        else:
            return self.non_recursive_binary_search(name)

    def display(self):
        for name, mobile in self.contacts:
            print(f"{name}: {mobile}")


if __name__ == "__main__":
    phonebook = Phonebook()

    while True:
        print("\n1. Insert a contact")
        print("2. Search for a contact (recursive)")
        print("3. Search for a contact (non-recursive)")
        print("4. Display phonebook")
        print("5. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            name = input("Enter name: ")
            mobile = input("Enter mobile number: ")
            result = phonebook.insert(name, mobile)
            print(result)

        elif choice == 2:
            name = input("Enter name to search: ")
            result = phonebook.search(name, recursive=True)
            if result:
                print(f"Contact found: {result[0]} - {result[1]}")
            else:
                print("Contact not found.")

        elif choice == 3:
            name = input("Enter name to search: ")
            result = phonebook.search(name, recursive=False)
            if result:
                print(f"Contact found: {result[0]} - {result[1]}")
            else:
                print("Contact not found.")

        elif choice == 4:
            phonebook.display()

        elif choice == 5:
            print("Exiting the phonebook program.")
            break
def fibonacci_search(arr, x):
    def generate_fibonacci_numbers(n):
        fib = [0, 1]
        while fib[-1] < n:
            fib.append(fib[-1] + fib[-2])
        return fib

    n = len(arr)
    fib = generate_fibonacci_numbers(n)

    offset = -1
    while fib[-2] > 1:
        i = min(offset + fib[-2], n - 1)
        if arr[i][0] < x:
            fib = fib[:-2]
            offset = i
        elif arr[i][0] > x:
            fib = fib[:-1]
        else:
            return i

    if offset + 1 < len(arr) and arr[offset + 1] and  arr[offset + 1][0]== x:
        return offset + 1
    else:
        return -1

def insert_friend(phonebook, name, number):
    index = fibonacci_search(phonebook, name)
    if index == -1:
        phonebook.append((name, number))
        phonebook.sort(key=lambda entry: entry[0])
        print(f"{name} has been added to your phonebook.")
    else:
        print(f"{name} is already in your phonebook.")

def main():
    phonebook = []
    while True:
        print("1. Search for a friend")
        print("2. Add a friend")
        print("3. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            search_name = input("Enter the name you want to search: ")
            index = fibonacci_search(phonebook, search_name)
            if index != -1:
                print(f"{search_name} found. Mobile number: {phonebook[index][1]}")
            else:
                print(f"{search_name} not found in your phonebook.")
        elif choice == 2:
            name = input("Enter the name of your friend: ")
            number = input("Enter the mobile number: ")
            insert_friend(phonebook, name, number)
        elif choice == 3:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()

