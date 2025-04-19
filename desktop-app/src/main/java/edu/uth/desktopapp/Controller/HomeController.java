package edu.uth.desktopapp.Controller;

import org.springframework.stereotype.Controller;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import edu.uth.desktopapp.Model.Home;
import edu.uth.desktopapp.Repository.HomeRepository;
import java.util.List;

@Controller
public class HomeController {

    @Autowired
    private HomeRepository homeRepository;

    @GetMapping("/")
    public String showProduct(Model model) {
        List<Home> ListSanPham = homeRepository.findAll();
        model.addAttribute("ListSanPham", ListSanPham);
        return "dashboard";
    }

    @GetMapping("/themsanpham")
    public String themSanPham(Model model) {
        model.addAttribute("home", new Home());
        model.addAttribute("ListSanPham", homeRepository.findAll());
        return "dashboard";
    }

    @GetMapping("/suasansham/{id}")
    public String suaSanPham(@PathVariable("id") String id, Model model) {
        Home sanPham = homeRepository.findById(id).orElse(null);
        model.addAttribute("home", sanPham);
        model.addAttribute("ListSanPham", homeRepository.findAll());
        return "dashboard";
    }

    @PostMapping("/luusanpham")
    public String luuSanPham(@ModelAttribute Home home) {
        homeRepository.save(home);
        return "redirect:/";
    }

    @GetMapping("/xoasanpham/{id}")
    public String xoaSanPham(@PathVariable("id") String id) {
        homeRepository.deleteById(id);
        return "redirect:/";
    }
}