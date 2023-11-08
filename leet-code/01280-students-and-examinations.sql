SELECT
  T1.student_id AS student_id,
  T1.student_name AS student_name,
  T1.subject_name AS subject_name,
  COUNT(T2.subject_name) AS attended_exams
FROM (SELECT * FROM Students CROSS JOIN Subjects) AS T1
LEFT JOIN Examinations AS T2 ON (
  T1.student_id = T2.student_id AND T1.subject_name = T2.subject_name
)
GROUP BY T1.student_id, T1.subject_name
ORDER BY T1.student_id ASC, T1.subject_name ASC;
