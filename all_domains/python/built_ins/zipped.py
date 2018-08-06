if __name__ == '__main__':
    numStudents, numCourses = map(int, input().split())
    gradesCourses = list()
    for course in range(numCourses):
        grades = list(map(float, input().split()))
        gradesCourses.append(grades)
    gradesStudents = zip(*gradesCourses)
    for student in gradesStudents:
        print(sum(student)/numCourses)
