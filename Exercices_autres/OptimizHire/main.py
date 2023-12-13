import sys
from PyPDF2 import PdfReader

# Vérifie s'il y a au moins un argument (le premier argument est le nom du script lui-même)
if len(sys.argv) < 2:
    print("Usage: python ton_script.py nom_du_fichier.pdf")
    sys.exit(1)

# Récupère le nom du fichier PDF passé en argument
pdf_file_name = sys.argv[1]

# Nom du fichier texte où tu veux sauvegarder le texte extrait
output_file_name = "texte_extrait.txt"

# Ouvre le fichier PDF en mode lecture binaire ('rb')
with open(pdf_file_name, 'rb') as pdf_file:
    pdf_reader = PdfReader(pdf_file)
    
    # Crée un fichier texte pour écrire le texte extrait
    with open(output_file_name, 'w', encoding='utf-8') as output_file:
        # Boucle à travers chaque page du PDF
        for page_num in range(len(pdf_reader.pages)):
            page = pdf_reader.pages[page_num]
            
            # Extrait le texte de la page
            text = page.extract_text()
            
            # Écrit le texte extrait dans le fichier texte
            output_file.write(text)
