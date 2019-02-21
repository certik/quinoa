# vim: filetype=sh:
# This is a comment
# Keywords are case-sensitive

title "Euler equations computing nonlinear energy growth"

inciter

  term 1.0
  nstep 10
  ttyi 1       # TTY output interval
  #dt 0.001
  cfl 0.25

  scheme diagcg

  partitioning
    algorithm mj
  end

  compflow
    depvar u
    physics euler
    problem nl_energy_growth
    alpha 0.25
    betax 1.0
    betay 0.75
    betaz 0.5
    r0 2.0
    ce -1.0
    kappa 0.8

    material
      id 1
      gamma 1.66666666666667 # =5/3 ratio of specific heats
    end

    bc_dirichlet
      sideset 1 2 3 4 5 6 end
    end
  end

  amr
   dtref true
   dtref_uniform true
   dtfreq 5
   refvar u end
   error jump
  end

  plotvar
    interval 1
  end

  diagnostics
    interval  1
    format    scientific
    error l2
  end

end
