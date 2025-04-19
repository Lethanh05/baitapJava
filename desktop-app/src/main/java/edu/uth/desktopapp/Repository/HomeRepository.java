package edu.uth.desktopapp.Repository;

import edu.uth.desktopapp.Model.Home;
import org.springframework.data.jpa.repository.JpaRepository;


public interface HomeRepository extends JpaRepository<Home, String> {
    }