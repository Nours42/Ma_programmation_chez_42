mysql -e
service mysql start
# cree un bdd si elle n'existe pas (normal)
mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
# je cree un user qui peut utiliser la bdd
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
# avec tous les droits
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
# je modifie mon user root pour qu'il est le mdp de la bdd (il n'avait pas de mdp jusque la)
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
# je rafraichit mysql pour prendre en compte les changements
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
# je sors de mysql
exec mysql_safe
# Mon script qui configure notre base de données est désormais 
# fonctionnel et devrait lancer le container mariadb sans soucis.