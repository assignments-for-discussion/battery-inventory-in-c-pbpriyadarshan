# Bucketing Batteries

The task is to count batteries by their usage.

## Battery Usage

A simple way to measure battery usage is to count the number of charge cycles.
We need to classify their usage as 'high', 'medium', 'low'
and count the number of batteries in each classification.

Batteries are classified as follows:

- charged less than 150 times: classified as `low`
- charged between 150 and 649 times: classified as `medium`
- charged 650 times or more: classified as `high`

The code in this repository has an empty function and a test.
Read the test to find out what's expected from the code.
Of course, the test fails now, since the function isn't implemented.

Implement the function to classify correctly and pass the test.

## Evaluation Criteria

- Readability: including variable names, code-flow, useage of comments only when necessary
- Improvements to existing code and tests
- Precision: adding new tests (such as boundary conditions)
