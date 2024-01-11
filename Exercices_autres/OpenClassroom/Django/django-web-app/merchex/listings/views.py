from django.http import HttpResponse
from django.shortcuts import render, redirect
from django.core.mail import send_mail

from listings.models import Band
from listings.models import Listing
from listings.forms import BandForm, ListingForm, ContactUsForm

def band_list(request):
    bands = Band.objects.all()
    return render(request,
            'listings/band_list.html',
            {'bands': bands})

def band_detail(request, id):
    band = Band.objects.get(id=id)
    return render(request,
            'listings/band_detail.html',
            {'band': band})

def band_create(request):

    if request.method == 'POST':
        form = BandForm(request.POST)

        if form.is_valid():
            # créer une nouvelle « Band » et la sauvegarder dans la db
            band = form.save()
            # redirige vers la page de détail du groupe que nous venons de créer
            # nous pouvons fournir les arguments du motif url comme arguments à la fonction de redirection
            return redirect('band-detail', band.id)
    else:
        form = BandForm()
        
    return render(request,
            'listings/band_create.html',
            {'form': form})

def band_update(request, id):
    band = Band.objects.get(id=id)

    if request.method == 'POST':
        form = BandForm(request.POST, instance=band)
        if form.is_valid():
            form.save()
            return redirect('band-detail', band.id)
    else:
        form = BandForm(instance=band)  # on pré-remplir le formulaire avec un groupe existant
    return render(request,
                    'listings/band_update.html',
                    {'form': form})

def band_delete(request, id):
    band = Band.objects.get(id=id)

    if request.method == 'POST':
        band.delete()
        return redirect('band-list')
    return render(request,
                    'listings/band_delete.html',
                    {'band': band})

def about(request):
    return render(request,
            'listings/about.html')

def listings_list(request):
    listings = Listing.objects.all()
    return render(request,
            'listings/listings_list.html',
            {'listings': listings})

def listings_detail(request, id):
    listing = Listing.objects.get(id=id)
    return render(request,
            'listings/listings_detail.html',
            {'listing': listing})

def listings_create(request):

    if request.method == 'POST':
        form = ListingForm(request.POST)

        if form.is_valid():
            # créer une nouvelle « Band » et la sauvegarder dans la db
            listing = form.save()
            # redirige vers la page de détail du groupe que nous venons de créer
            # nous pouvons fournir les arguments du motif url comme arguments à la fonction de redirection
            return redirect('listing-detail', listing.id)
    else:
        form = ListingForm()
        
    return render(request,
            'listings/listings_create.html',
            {'form': form})

def listings_update(request, id):
    listings = Listing.objects.get(id=id)

    if request.method == 'POST':
        form = ListingForm(request.POST, instance=listings)
        if form.is_valid():
            form.save()
            return redirect('listing-detail', listings.id)
    else:
        form = ListingForm(instance=listings)  # on pré-remplir le formulaire avec un groupe existant
    return render(request,
                    'listings/listings_update.html',
                    {'form': form})

def listings_delete(request, id):
    listings = Listing.objects.get(id=id)

    if request.method == 'POST':
        listings.delete()
        return redirect('listing-list')
    return render(request,
                    'listings/listings_delete.html',
                    {'listings': listings})

def contact(request):

    if request.method == 'POST':
        form = ContactUsForm(request.POST)

        if form.is_valid():
            send_mail(
                subject=f'Message from {form.cleaned_data["name"] or "anonyme"} via Merchex Contact Us form',
                message=form.cleaned_data['message'],
                from_email=form.cleaned_data['email'],
                recipient_list=['admin@merchex.xyz']
            )
        return redirect('email-sent')
    else:
        form = ContactUsForm()

    return render(request,
            'listings/contact.html',
            {'form': form})


