import sys
import PyPDF2

# Vérifie s'il y a au moins un argument (le premier argument est le nom du script lui-même)
if len(sys.argv) < 2:
    print("Usage: python ton_script.py nom_du_fichier.pdf")
    sys.exit(1)

# Récupère le nom du fichier PDF passé en argument
pdf_file_name = sys.argv[1]

# Ouvre le fichier PDF en mode lecture binaire ('rb')
with open(pdf_file_name, 'rb') as pdf_file:
    pdf_reader = PyPDF2.PdfFileReader(pdf_file)
    
    # Boucle à travers chaque page du PDF
    for page_num in range(pdf_reader.numPages):
        page = pdf_reader.getPage(page_num)
        
        # Extrait le texte de la page
        text = page.extractText()
        
        # Utilise le texte pour tes besoins (classification, traitement, etc.)
        # Par exemple, imprime le texte de chaque page
        print(text)
