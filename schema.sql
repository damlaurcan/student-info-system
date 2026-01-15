

-- Students table **************
CREATE TABLE IF NOT EXISTS students (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(150) UNIQUE NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Courses table*********
CREATE TABLE IF NOT EXISTS courses (
    id SERIAL PRIMARY KEY,
    course_name VARCHAR(100) NOT NULL,
    course_code VARCHAR(20) UNIQUE NOT NULL
);

-- Enrollment table *************
CREATE TABLE IF NOT EXISTS enrollments (
    student_id INT NOT NULL,
    course_id INT NOT NULL,
    enrolled_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (student_id, course_id),
    CONSTRAINT fk_student
        FOREIGN KEY (student_id)
        REFERENCES students(id)
        ON DELETE CASCADE,
    CONSTRAINT fk_course
        FOREIGN KEY (course_id)
        REFERENCES courses(id)
        ON DELETE CASCADE
);
