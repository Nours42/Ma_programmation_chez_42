CREATE DATABASE IF NOT EXISTS wordpress;
SELECT * FROM wp_users WHERE user_login = 'sdestann';
DELETE FROM wp_users WHERE user_login = 'sdestann';
CREATE USER IF NOT EXISTS 'sdestann'@'%' IDENTIFIED BY '972182';
GRANT ALL PRIVILEGES ON wordpress.* TO 'sdestann'@'%';
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY 'test';
