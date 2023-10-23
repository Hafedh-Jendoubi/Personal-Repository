<?php

namespace App\Controller;

use App\Entity\Book;
use App\Form\BookType;
use App\Repository\BookRepository;
use Doctrine\Persistence\ManagerRegistry;
use phpDocumentor\Reflection\Types\Null_;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

class BookController extends AbstractController
{
    #[Route('/book', name: 'app_book')]
    public function index(): Response
    {
        return $this->render('book/index.html.twig', [
            'controller_name' => 'BookController',
        ]);
    }

    #[Route('/listBooks', name: 'list_books')]
    public function listBook(BookRepository $repository)
    {
        return $this->render('book/showBooks.html.twig', array('tabBooks'=>$repository->findAll()));
    }

    #[Route('/addBook', name: 'add_book')]
    public function addBook(Request $request, ManagerRegistry $managerRegistry){
        $book = new Book();

        $form = $this->createForm(BookType::class, $book);
        $form->handleRequest($request);
        if($form->isSubmitted()){
            $em = $managerRegistry->getManager();
            $book->setPublished(True);
            $book->getAuthor()->setNbrBooks($book->getAuthor()->getNbrBooks()+1);
            $em->persist($book);
            $em->flush();

            return $this->redirectToRoute("list_books");
        }

        return $this->renderForm("book/addBook.html.twig", ['BookForm'=>$form]);
    }

    #[Route('/deletebook/{ref}', name: 'delete_book')]
    public function deleteBook(ManagerRegistry $managerRegistry, $ref, BookRepository $repository){
        $book = $repository->find($ref);
        $em= $managerRegistry->getManager();
        $em->remove($book);
        $em->flush();

        return $this->redirectToRoute("list_books");
    }

    #[Route('/updateBook/{ref}', name: 'update_book')]
    public function updateBook($ref,BookRepository $repository,Request $request,ManagerRegistry $managerRegistry)
    {
        $book= $repository->find($ref);
        $form= $this->createForm(BookType::class,$book);
        $form->handleRequest($request);
        if($form->isSubmitted()){
            $em= $managerRegistry->getManager();
            $book->setPublished(True);
            $em->flush();
            return $this->redirectToRoute("list_books");
        }
        return $this->renderForm("book/updateBook.html.twig",["formBook"=>$form]);
    }

    #[Route('/showBook/{ref}', name: 'show_book')]
    public function showBook($ref, BookRepository $repository)
    {
        $book = $repository->find($ref);
        return $this->render('book/showBook.html.twig', array('title'=>$book->getTitle(),
                                                                    'author'=>$book->getAuthor(),
                                                                    'date'=>$book->getDatePublication()));
    }
}
