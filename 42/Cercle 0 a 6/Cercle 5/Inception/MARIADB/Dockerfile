# rappel des consignes : MARIADB sans NGINX

FROM debian:bookworm
# bookworm est la version 12.2 de debian c'est la derniere version stable en oct 2023

# update des paquets (eventuellement) et install de nginx
RUN apt update && apt upgrade && apt install mariadb-server -y
# on ecrase le fichier de conf "de base" par celui prevu et aui est dans le dossier config
COPY config/50-server.conf /etc/mysql/mariadb.conf.d/50-server.conf
# je lance mysql (rappel mariaDB et mysql est la meme chose sauf que mysql est devenu payant)
RUN service mysql start
# cree un bdd si elle n'existe pas (normal)
RUN mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
# je cree un user qui peut utiliser la bdd
RUN mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
# avec tous les droits
RUN mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
# je modifie mon user root pour qu'il est le mdp de la bdd (il n'avait pas de mdp jusque la)
RUN mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
# je rafraichit mysql pour prendre en compte les changements
RUN mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
# je sors de mysql
RUN exec mysql_safe
# Mon script qui configure notre base de données est désormais 
# fonctionnel et devrait lancer le container mariadb sans soucis.