<?php

namespace App\Controller;

use App\Entity\Author;
use App\Form\AuthorType;
use App\Repository\AuthorRepository;
use Doctrine\DBAL\Types\TextType;
use Doctrine\Persistence\ManagerRegistry;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Form\Extension\Core\Type\ResetType;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

class AuthorController extends AbstractController
{
    #[Route('/author', name: 'app_author')]
    public function index(): Response
    {
        return $this->render('author/index.html.twig', [
            'controller_name' => 'AuthorController',
        ]);
    }

    #[Route('/showAuthor/{username}/{email}/{nbBooks}', name: 'show_Author')]
    public function showAuthor($username, $email, $nbBooks)
    {
        return $this->render('author/showAuthor.html.twig', array('nameAuthor'=>$username, 'email'=>$email, 'nbBooks'=>$nbBooks));
    }

    #[Route('/listauthor', name: 'list_author')]
    public function listAuthor(AuthorRepository $repository)
    {
        /*$authors = array(
            array('id' => 1, 'username' => 'Victor Hugo','email'=> 'victor.hugo@gmail.com', 'nb_books'=> 100),
            array ('id' => 2, 'username' => 'William Shakespeare','email'=> 'william.shakespeare@gmail.com','nb_books' => 200),
            array('id' => 3, 'username' => 'Taha Hussein','email'=> 'taha.hussein@gmail.com','nb_books' => 300)
        );*/

        $authors = $repository->findAll();

        return $this->render('author/showAuthors.html.twig', array('tabAuthors'=>$authors));
    }


    #[Route('/addauthor', name: 'add_author')]
    public function addAuthor(Request $request, ManagerRegistry $managerRegistry)
    {
        $author = new Author();

        $form = $this->createForm(AuthorType::class, $author);
        $form->handleRequest($request);
        if($form->isSubmitted()){
            $em = $managerRegistry->getManager();
            $author->setNbrBooks(0);
            $em->persist($author);
            $em->flush();
            return $this->redirectToRoute("list_author");
        }

        //$author = new Author("Hafedh", "hafedh.jendoubi@esprit.tn");
        //$author->setEmail();
        //$author->setUsername();
        #$em= $this->getDoctrine()->getManager();
//        $em= $managerRegistry->getManager();
//        $em->persist($author);
//        $em->flush();

        return $this->renderForm("author/showFormulaire.html.twig", array('FormA'=>$form));
    }

    #[Route('/updateauthor/{id}', name: 'update_author')]
    public function updateAuthor($id,AuthorRepository $repository,ManagerRegistry $managerRegistry)
    {
        $author = $repository->findBy($id);

        $author->setEmail("author5@gmail.com");
        $author->setUsername("author5");
        #$em= $this->getDoctrine()->getManager();
        $em= $managerRegistry->getManager();
        $em->flush();

        return $this->redirectToRoute("list_author");
    }

    #[Route('/deleteauthor/{id}', name: 'delete_author')]
    public function deleteAuthor(ManagerRegistry $managerRegistry, $id, AuthorRepository $repository)
    {
        $author = $repository->find($id);

        $em= $managerRegistry->getManager();
        if($author->getNbrBooks() == 0){
            $em->remove($author);
            $em->flush();
        }else{
            return new Response("Error");
        }

        return $this->redirectToRoute("list_author");
    }
}