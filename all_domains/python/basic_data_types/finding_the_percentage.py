# -*- coding: utf8 -*-

import math

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    # Obtain list of scores from given student.
    scoresList = student_marks[query_name]
    # Compute average of the student's marks.

    # Return an accurate floating point sum of values in the iterable. Avoids
    # loss of precision by tracking multiple intermediate partial sums.

    # The algorithm’s accuracy depends on IEEE-754 arithmetic guarantees and the
    # typical case where the rounding mode is half-even. On some non-Windows
    # builds, the underlying C library uses extended precision addition and may
    # occasionally double-round an intermediate sum causing it to be off in its
    # least significant bit.

    sumScores = math.fsum(scoresList)

    print("%.2f" % (sumScores/3.0))
